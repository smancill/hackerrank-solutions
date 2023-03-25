// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <string>


auto counter_game(unsigned long n) -> std::string
{
    auto mask = 1UL << 63;
    auto turn = 0;
    while (n > 1) {
        while (mask > n) {
            mask >>= 1;
        }
        if (mask == n) {
            n >>= 1;
        } else {
            n -= mask;
        }
        turn ^= 1;
    }
    return turn == 1 ? "Louise" : "Richard";
}


auto main() -> int
{
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        unsigned long n;
        std::cin >> n;

        auto winner = counter_game(n);

        std::cout << winner << '\n';
    }

    return 0;
}
