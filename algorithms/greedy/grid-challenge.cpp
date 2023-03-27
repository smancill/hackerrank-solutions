// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


auto grid_challenge(std::vector<std::string> grid) -> std::string
{
    const auto n = ssize(grid);
    const auto m = ssize(grid[0]);

    // rows
    for (auto i = 0z; i < n; ++i) {
        std::ranges::sort(grid[i]);
    }

    // columns
    for (auto j = 0z; j < m; ++j) {
        for (auto i = 0z; i < n - 1; ++i) {
            if (grid[i+1][j] < grid[i][j]) {
                return "NO";
            }
        }
    }

    return "YES";
}


auto main() -> int
{
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        auto grid = std::vector<std::string>{};
        grid.reserve(n);
        std::copy_n(std::istream_iterator<std::string>{std::cin}, n,
                    std::back_inserter(grid));

        auto result = grid_challenge(std::move(grid));

        std::cout << result << std::endl;
    }

    return 0;
}
