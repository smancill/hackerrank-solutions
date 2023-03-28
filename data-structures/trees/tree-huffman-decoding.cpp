// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include "huffman-tree.hpp"

#include <iostream>
#include <sstream>
#include <string>


auto decode_huffman(const HuffmanTree& tree) -> std::string
{
    auto ss = std::ostringstream{};
    const auto* node = tree.root();
    for (auto c : tree.str()) {
        node = c == '0' ? node->left() : node->right();
        if (!node->left() && !node->right()) {
            ss << node->data();
            node = tree.root();
        }
    }
    return ss.str();
}


auto main() -> int
{
    std::string s;
    std::cin >> s;

    auto tree = HuffmanTree{s};

    auto result = decode_huffman(tree);

    std::cout << result << std::endl;

    return 0;
}
