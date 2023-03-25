// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>


auto page_count(int n, int p) -> int
{
    auto total_count = n / 2;
    auto target_count = p / 2;
    auto backward_count = total_count - target_count;
    return std::min(target_count, backward_count);
}


auto main() -> int
{
    int n;
    std::cin >> n;

    int p;
    std::cin >> p;

    auto result = page_count(n, p);

    std::cout << result << std::endl;

    return 0;
}
