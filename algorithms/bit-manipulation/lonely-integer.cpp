// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


auto lonely_integer(std::span<const int> numbers) -> int
{
    auto n = 0;
    for (auto i : numbers) {
        n ^= i;
    }
    return n;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto numbers = std::vector<int>{};
    numbers.reserve(n);
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto result = lonely_integer(numbers);

    std::cout << result << std::endl;

    return 0;
}
