// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <vector>

constexpr auto M = 1'000'000'007;


auto pow(long base, int exp, int mod) -> long
{
    auto result = 1L;
    for (auto i = 0; i < exp; ++i) {
        result *= base;
        result %= mod;
    }
    return result;
}


auto row_walls(int m) -> std::vector<long>
{
    auto walls = std::vector<long>{0, 1, 2, 4, 8};
    walls.resize(m + 1);
    for (auto i = 5; i <= m; ++i) {
        walls[i] = walls[i-1] + walls[i-2] + walls[i-3] + walls[i-4];
        walls[i] %= M;
    }
    return walls;
}


auto all_walls(int n, int m) -> std::vector<long>
{
    auto walls = row_walls(m);
    for (auto& count : walls) {
        count = pow(count, n, M);
    }
    return walls;
}


auto solid_walls(const std::vector<long>& walls) -> std::vector<long>
{
    auto solid = std::vector<long>{0, 1};
    solid.reserve(size(walls));

    for (auto i = 2; i <= ssize(walls); ++i) {
        auto invalid = 0L;
        for (auto j = 1; j < i; ++j) {
            invalid += solid[j] * walls[i-j];
            invalid %= M;
        }
        auto valid = (M + walls[i] - invalid) % M;
        solid.push_back(valid);
    }

    return solid;
}


auto lego_blocks(int n, int m) -> long
{
    auto walls = all_walls(n, m);
    auto solid = solid_walls(walls);
    return solid[m];
}


auto main() -> int
{
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        int n;
        int m;
        std::cin >> n >> m;

        auto solid = lego_blocks(n, m);

        std::cout << solid << '\n';
    }

    return 0;
}
