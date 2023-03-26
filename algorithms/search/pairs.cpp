// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <span>
#include <vector>


auto pairs(int k, std::span<const int> numbers) -> int
{
    auto s = std::set<int>{numbers.begin(), numbers.end()};
    auto count = 0;
    for (auto x : s) {
        if (s.contains(x + k)) {
            ++count;
        }
    }
    return count;
}


auto main() -> int
{
    int n, k;
    std::cin >> n >> k;

    auto numbers = std::vector<int>{};
    numbers.reserve(n);
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto result = pairs(k, numbers);

    std::cout << result << std::endl;

    return 0;
}
