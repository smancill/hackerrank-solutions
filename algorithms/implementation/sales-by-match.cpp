// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <ranges>
#include <span>
#include <vector>


auto sock_merchant(std::span<const int> socks) -> int
{
    auto pairs = std::map<int, int>{};
    for (auto s : socks) {
        pairs[s] += 1;
    }
    auto total = 0;
    for (auto count : std::views::values(pairs)) {
        total += count / 2;
    }
    return total;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto socks = std::vector<int>{};
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(socks));

    auto result = sock_merchant(socks);

    std::cout << result << std::endl;

    return 0;
}
