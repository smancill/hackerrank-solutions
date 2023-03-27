// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


auto find_median(std::vector<int> v) -> int
{
    std::ranges::sort(v);
    auto n = ssize(v);
    return (n % 2 == 1) ? v[n/2] : (v[n/2-1] + v[n/2]) / 2;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto numbers = std::vector<int>{};
    numbers.reserve(n);
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto median = find_median(std::move(numbers));

    std::cout << median << std::endl;

    return 0;
}
