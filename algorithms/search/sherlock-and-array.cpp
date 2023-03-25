// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <span>
#include <vector>


auto balanced_sums(std::span<const int> numbers) -> std::string
{
    auto total_sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    auto left_sum = 0;
    for (auto x : numbers) {
        auto right_sum = total_sum - left_sum - x;
        if (left_sum == right_sum) {
            return "YES";
        }
        left_sum += x;
    }
    return "NO";
}


auto main() -> int
{
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        auto numbers = std::vector<int>{};
        std::copy_n(std::istream_iterator<int>{std::cin}, n,
                    std::back_inserter(numbers));

        auto result = balanced_sums(numbers);

        std::cout << result << '\n';
    }

    return 0;
}
