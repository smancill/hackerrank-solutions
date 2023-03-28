// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <regex>
#include <string>


auto time_conversion(const std::string& s) -> std::string
{
    auto r = std::regex(R"((\d\d)(:\d\d:\d\d)([AP]M))");
    auto m = std::smatch{};
    std::regex_match(s, m, r);

    auto h = m.str(1);
    if (m.str(3) == "AM") {
        if (h == "12") {
            h = "00";
        }
    } else {
        auto i = std::stoi(h);
        if (i < 12) {
            h = std::to_string(i + 12);
        }
    }

    return h + m.str(2);
}


auto main() -> int
{
    std::string time;
    std::cin >> time;

    auto militar_time = time_conversion(time);

    std::cout << militar_time << std::endl;

    return 0;
}
