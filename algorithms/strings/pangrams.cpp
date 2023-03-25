// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <array>
#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>


auto pangrams(std::string_view s) -> std::string
{
    auto letters = std::array<char, 26>{0};
    for (auto c : s) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
            letters[c - 'a'] |= 1;
        }
    }
    auto count = std::accumulate(letters.begin(), letters.end(), 0);
    return count == 26 ? "pangram" : "not pangram";
}


auto main() -> int
{
    std::string s;
    std::getline(std::cin, s);

    auto r = pangrams(s);

    std::cout << r << std::endl;

    return 0;
}
