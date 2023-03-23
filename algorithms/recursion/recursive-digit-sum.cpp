// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <string>
#include <string_view>


// The challenge requires recursion, but a simple while loop can do it
auto super_digit(std::string_view n, int k) -> int
{
    auto sum = 0L;
    for (auto c : n) {
        sum += c - '0';
    }
    sum *= k;

    auto super = sum;
    while (super >= 10) {
        auto sum = 0;
        while (super > 0) {
            sum += super % 10;
            super /= 10;
        }
        super = sum;
    }

    return super;
}


auto main() -> int
{
    std::string n;
    int k;
    std::cin >> n >> k;

    auto d = super_digit(n, k);

    std::cout << d << std::endl;

    return 0;
}
