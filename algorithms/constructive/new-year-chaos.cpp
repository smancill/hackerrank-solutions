// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <vector>


auto minimum_bribes(std::vector<int> q) -> std::optional<int>
{
    auto sum = 0;
    for (auto i = ssize(q) - 1; i > 1; --i) {
        auto p = i + 1;
        if (q[i] == p) {
            continue;
        } else if (q[i - 1] == p) {
            q[i - 1] = q[i];
            q[i] = p;
            sum += 1;
        } else if (q[i - 2] == p) {
            q[i - 2] = q[i - 1];
            q[i - 1] = q[i];
            q[i] = p;
            sum += 2;
        } else {
            return std::nullopt;
        }
    }
    if (q[1] == 1) {
        sum += 1;
    }
    return sum;
}


auto main() -> int
{
    int t;
    std::cin >> t;

    while (t-- > 0) {
        int n;
        std::cin >> n;

        auto queue = std::vector<int>{};
        queue.reserve(n);
        std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(queue));

        auto result = minimum_bribes(queue);
        if (result) {
            std::cout << *result << '\n';
        } else {
            std::cout << "Too chaotic\n";
        }
    }

    return 0;
}
