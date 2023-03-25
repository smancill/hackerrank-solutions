// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>


auto sum_xor(long n) -> long
{
    auto counter = 1L;
    while (n > 0) {
        if ((n & 1) == 0) {
            counter <<= 1;
        }
        n >>= 1;
    }
    return counter;
}


auto main() -> int
{
    long n;
    std::cin >> n;

    auto result = sum_xor(n);

    std::cout << result << std::endl;

    return 0;
}
