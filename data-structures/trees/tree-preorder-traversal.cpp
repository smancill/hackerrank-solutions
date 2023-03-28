// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include "binary-tree.hpp"

#include <functional>
#include <iostream>


template<typename T, typename F>
auto pre_order(const BinaryNode<T>* root, F visitor) -> void
{
    if (!root) {
        return;
    }
    std::invoke(visitor, root->data());
    pre_order(root->left(), visitor);
    pre_order(root->right(), visitor);
}


auto main() -> int
{
    auto tree = BinaryTree<int>{};

    int n;
    std::cin >> n;

    for (auto i = 0; i < n; ++i) {
        int data;
        std::cin >> data;
        tree.insert(data);
    }

    pre_order(tree.root(), [](int data) {
        std::cout << data << ' ';
    });
    std::cout << '\n';

    return 0;
}
