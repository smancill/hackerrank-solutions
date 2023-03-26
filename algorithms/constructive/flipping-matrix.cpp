// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

using Matrix = std::vector<std::vector<int>>;


auto flipping_matrix(const Matrix& matrix) -> int
{
    const auto n = ssize(matrix) / 2;
    const auto last = ssize(matrix) - 1;

    auto sum = 0;
    for (auto i = 0z; i < n; ++i) {
        for (auto j = 0z; j < n; ++j) {
            sum += std::max({
                matrix[i][j],
                matrix[i][last - j],
                matrix[last - i][j],
                matrix[last - i][last - j]
            });
        }
    }

    return sum;
}


auto main() -> int
{
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; ++i) {
        int n;
        std::cin >> n;

        auto matrix = Matrix(2 * n);
        for (auto& row : matrix) {
            std::copy_n(std::istream_iterator<int>{std::cin}, 2 * n,
                        std::back_inserter(row));
        }

        auto max = flipping_matrix(matrix);

        std::cout << max << '\n';
    }

    return 0;
}
