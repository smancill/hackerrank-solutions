// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

using Matrix = std::vector<std::vector<int>>;


auto diagonal_difference(const Matrix& m) -> int
{
    const auto n = ssize(m);

    auto sum1 = 0;
    for (auto i = 0z; i < n; ++i) {
        sum1 += m[i][i];
    }

    auto sum2 = 0;
    for (auto i = 0z; i < n; ++i) {
        sum2 += m[i][n-1-i];
    }

    return std::abs(sum1 - sum2);
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto matrix = Matrix(n);
    for (auto& row : matrix) {
        row.reserve(n);
        std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(row));
    }

    auto median = diagonal_difference(matrix);

    std::cout << median << std::endl;

    return 0;
}
