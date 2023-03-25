// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


struct Query {
    int type;
    int x;
    int y;
};


auto operator>>(std::istream& is, Query& q) -> std::istream&
{
    return is >> q.type >> q.x >> q.y;
}


auto dynamic_array(int n, std::span<const Query> queries) -> std::vector<int>
{
    auto arr = std::vector<std::vector<int>>(n);
    auto ans = std::vector<int>{};
    auto last = 0;
    for (const auto& [q, x, y] : queries) {
        auto i = (x ^ last) % n;
        switch (q) {
            case 1:
                arr[i].push_back(y);
                break;
            case 2:
                last = arr[i][y % ssize(arr[i])];
                ans.push_back(last);
                break;
        }
    }
    return ans;
}


auto main() -> int
{
    int n;
    std::cin >> n;

    int q;
    std::cin >> q;

    auto queries = std::vector<Query>{};
    queries.reserve(q);
    std::copy_n(std::istream_iterator<Query>{std::cin}, q, std::back_inserter(queries));

    auto result = dynamic_array(n, queries);

    for (auto x : result) {
        std::cout << x << '\n';
    }

    return 0;
}
