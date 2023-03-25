// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>


auto max_min(int k, std::vector<int> v) -> int
{
    std::ranges::sort(v);

    auto min = std::numeric_limits<int>::max();
    for (int i = 0z; i <= ssize(v) - k; ++i) {
        auto diff = v[i+k-1] - v[i];
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    int k;
    std::cin >> k;

    auto numbers = std::vector<int>{};
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto result = max_min(k, std::move(numbers));

    std::cout << result << std::endl;

    return 0;
}
