// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <span>
#include <vector>
#include <utility>


auto mini_max_sum(std::span<const int> numbers) -> std::pair<long, long>
{
    auto sum = 0L;
    auto min = std::numeric_limits<long>::max();
    auto max = std::numeric_limits<long>::min();
    for (auto x : numbers) {
        sum += x;
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }
    auto min_sum = sum - max;
    auto max_sum = sum - min;
    return {min_sum, max_sum};
}


auto main() -> int
{
    auto numbers = std::vector<int>{};
    std::copy(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{},
              std::back_inserter(numbers));

    auto [min, max] = mini_max_sum(numbers);

    std::cout << min << ' ' << max << std::endl;

    return 0;
}
