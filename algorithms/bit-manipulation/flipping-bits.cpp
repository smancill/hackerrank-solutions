// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>


auto flipping_bits(unsigned n) -> unsigned
{
    return ~n;
}


auto main() -> int
{
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; ++i) {
        unsigned n;
        std::cin >> n;

        auto result = flipping_bits(n);

        std::cout << result << '\n';
    }

    return 0;
}
