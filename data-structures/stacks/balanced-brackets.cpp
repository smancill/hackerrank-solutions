// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <string_view>


auto is_balanced(std::string_view s) -> std::string
{
    auto b = std::stack<char>();
    auto m = std::map<char, char>{{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for (auto c : s) {
        if (m.contains(c)) {
            b.push(c);
        } else {
            if (b.empty()) {
                return "NO";
            }
            auto o = b.top();
            if (m[o] != c) {
                return "NO";
            }
            b.pop();
        }
    }
    if (!b.empty()) {
        return "NO";
    }
    return "YES";
}


auto main() -> int
{
    int n;
    std::cin >> n;

    while (n-- > 0) {
        std::string s;
        std::cin >> s;

        auto b = is_balanced(s);

        std::cout << b << '\n';
    }

    return 0;
}
