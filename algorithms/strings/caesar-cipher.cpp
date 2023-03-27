// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <string>


auto caesar_cipher(std::string s, int k) -> std::string
{
    for (auto& c : s) {
        if ('a' <= c && c <= 'z') {
            c = 'a' + (c - 'a' + k) % 26;
        } else if ('A' <= c && c <= 'Z') {
            c = 'A' + (c - 'A' + k) % 26;
        }
    }
    return s;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    auto c = caesar_cipher(std::move(s), k);

    std::cout << c << std::endl;

    return 0;
}
