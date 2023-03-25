// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>


auto two_arrays(int k, std::vector<int> A, std::vector<int> B) -> std::string
{
    std::ranges::sort(A, std::greater{});
    std::ranges::sort(B);

    for (auto i = 0z; i < ssize(A); ++i) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}


auto main() -> int
{
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; ++i) {
        int n;
        int k;
        std::cin >> n >> k;

        auto A = std::vector<int>{};
        std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(A));

        auto B = std::vector<int>{};
        std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(B));

        auto result = two_arrays(k, std::move(A), std::move(B));

        std::cout << result << '\n';
    }
    return 0;
}
