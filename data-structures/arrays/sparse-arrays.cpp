// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


auto matching_strings(std::span<const std::string> strings,
                      std::span<const std::string> queries)
    -> std::vector<int>
{
    auto r = std::vector<int>{};
    r.reserve(queries.size());
    for (const auto& q : queries) {
        r.push_back(std::ranges::count(strings, q));
    }
    return r;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto strings = std::vector<std::string>{};
    strings.reserve(n);
    std::copy_n(std::istream_iterator<std::string>{std::cin}, n,
                std::back_inserter(strings));

    int q;
    std::cin >> q;

    auto queries = std::vector<std::string>{};
    queries.reserve(q);
    std::copy_n(std::istream_iterator<std::string>{std::cin}, q,
                std::back_inserter(queries));

    auto result = matching_strings(strings, queries);

    for (auto c : result) {
        std::cout << c << '\n';
    }

    return 0;
}
