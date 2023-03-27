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
    const auto m = std::map<char, char>{{'(', ')'}, {'{', '}'}, {'[', ']'}};

    auto b = std::stack<char>();
    for (auto c : s) {
        if (m.contains(c)) {
            b.push(c);
        } else {
            if (b.empty()) {
                return "NO";
            }
            auto o = b.top();
            if (m.at(o) != c) {
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

    for (auto i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        auto b = is_balanced(s);

        std::cout << b << '\n';
    }

    return 0;
}
