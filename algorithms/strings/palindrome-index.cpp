// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <string>
#include <string_view>


struct is_palindrome {
    int i;
    int j;

    explicit operator bool() const
    {
        return i >= j;
    }
};


auto check_palindrome(std::string_view s) -> is_palindrome
{
    auto i = 0;
    auto j = static_cast<int>(ssize(s) - 1);
    for (; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            break;
        }
    }
    return {i, j};
}


auto palindrome_index(std::string_view s) -> int
{
    const auto p = check_palindrome(s);
    if (p) {
        return -1;
    }
    const auto [i, j] = p;
    if (s[i + 1] == s[j]) {
        if (check_palindrome(s.substr(i + 1, j - i))) {
            return i;
        }
    }
    if (s[i] == s[j - 1]) {
        if (check_palindrome(s.substr(i, j - i))) {
            return j;
        }
    }
    return -1;
}


auto main() -> int
{
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; ++i) {
        std::string s;
        std::cin >> s;

        auto idx = palindrome_index(s);

        std::cout << idx << '\n';
    }

    return 0;
}
