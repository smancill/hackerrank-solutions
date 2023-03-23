// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


struct Station {
    int petrol;
    int distance;
};


auto operator>>(std::istream& is, Station& station) -> std::istream&
{
    return is >> station.petrol >> station.distance;
}


auto truck_tour(std::span<const Station> pumps) -> int
{
    auto queue = std::deque<Station>{pumps.begin(), pumps.end()};

    auto start = 0;
    auto count = 0;
    auto tank = 0;

    while (count < ssize(queue)) {
        auto [petrol, distance] = queue.front();

        ++count;
        tank += petrol;
        if (tank >= distance) {
            tank -= distance;
        } else {
            start += count;
            count = 0;
            tank = 0;
        }

        queue.push_back(std::move(queue.front()));
        queue.pop_front();
    }

    return start;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto stations = std::vector<Station>{};
    stations.reserve(n);
    std::copy_n(std::istream_iterator<Station>{std::cin}, n,
                std::back_inserter(stations));

    auto start = truck_tour(stations);

    std::cout << start << std::endl;

    return 0;
}
