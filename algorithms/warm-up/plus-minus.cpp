// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>


struct Ratios {
    float positives;
    float negatives;
    float zeros;
};


auto plus_minus(std::span<const int> numbers) -> Ratios
{
    auto positives = 0.0f;
    auto negatives = 0.0f;
    auto zeros = 0.0f;

    for (auto x : numbers) {
        if (x > 0) {
            ++positives;
        } else if (x < 0) {
            ++negatives;
        } else {
            ++zeros;
        }
    }

    positives /= ssize(numbers);
    negatives /= ssize(numbers);
    zeros /= ssize(numbers);

    return {positives, negatives, zeros};
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto numbers = std::vector<int>{};
    std::copy_n(std::istream_iterator<int>{std::cin}, n, std::back_inserter(numbers));

    auto ratios = plus_minus(numbers);

    std::cout << std::setprecision(6) << std::fixed
              << ratios.positives << '\n'
              << ratios.negatives << '\n'
              << ratios.zeros << '\n';

    return 0;
}
