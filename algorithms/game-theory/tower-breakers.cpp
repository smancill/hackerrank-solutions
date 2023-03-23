// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>


auto tower_breakers(int n, int m) -> int
{
    if (m == 1) {
        return 2;
    } else if (n % 2 == 0) {
        return 2;
    } else {
        return 1;
    }
}


auto main() -> int
{
    int t;
    std::cin >> t;

    while (t-- > 0) {
        int n, m;
        std::cin >> n >> m;

        auto winner = tower_breakers(n, m);

        std::cout << winner << '\n';
    }

    return 0;
}
