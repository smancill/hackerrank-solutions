// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


auto counting_sort(std::span<const int> numbers) -> std::vector<int>
{
    auto freq = std::vector<int>(100);
    for (auto x : numbers) {
        freq[x] += 1;
    }
    return freq;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto numbers = std::vector<int>{};
    numbers.reserve(n);
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto freq = counting_sort(numbers);

    for (auto f : freq) {
        std::cout << f << ' ';
    }
    std::cout << std::endl;

    return 0;
}
