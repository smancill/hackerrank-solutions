// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


auto birthday(std::span<const int> s, int d, int m) -> int
{
    auto sum = 0;
    for (auto i = 0; i < m; ++i) {
        sum += s[i];
    }
    auto count = 0;
    if (sum == d) {
        ++count;
    }
    for (auto i = 1z; i <= ssize(s) - m; ++i) {
        sum -= s[i - 1];
        sum += s[i + m - 1];
        if (sum == d) {
            ++count;
        }
    }
    return count;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto squares = std::vector<int>{};
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(squares));

    int d;
    int m;
    std::cin >> d >> m;

    auto result = birthday(squares, d, m);

    std::cout << result << std::endl;

    return 0;
}
