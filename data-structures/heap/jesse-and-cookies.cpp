// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


auto mix_cookies(int k, std::vector<int> cookies) -> int
{
    using Compare = std::greater<int>;

    auto count = 0;
    std::make_heap(cookies.begin(), cookies.end(), Compare{});

    while (cookies.front() < k && cookies.size() >= 2) {
        std::pop_heap(cookies.begin(), cookies.end(), Compare{});
        auto c1 = cookies.back();
        cookies.pop_back();

        std::pop_heap(cookies.begin(), cookies.end(), Compare{});
        auto c2 = cookies.back();
        cookies.pop_back();

        auto mixed = c1 + 2 * c2;
        cookies.push_back(mixed);
        std::push_heap(cookies.begin(), cookies.end(), Compare{});

        ++count;
    }

    return cookies.front() >= k ? count : -1;
}


auto main() -> int
{
    int n;
    int k;
    std::cin >> n >> k;

    auto cookies = std::vector<int>{};
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(cookies));

    auto c = mix_cookies(k, std::move(cookies));

    std::cout << c << std::endl;

    return 0;
}
