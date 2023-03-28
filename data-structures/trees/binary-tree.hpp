// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_

#include <memory>


template<typename T>
class BinaryTree;


template<typename T>
class BinaryNode {
    friend BinaryTree<T>;

    BinaryNode(T data)
      : data_{std::move(data)}
    {}

public:
    auto data() const noexcept -> const T&
    {
        return data_;
    }

    auto left() const noexcept -> const BinaryNode*
    {
        return left_.get();
    }

    auto right() const noexcept -> const BinaryNode*
    {
        return right_.get();
    }

private:
    T data_;
    std::unique_ptr<BinaryNode> left_;
    std::unique_ptr<BinaryNode> right_;
};


template<typename T>
class BinaryTree {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using node_type = BinaryNode<T>;

    auto insert(T data) -> void
    {
        insert(root_, std::move(data));
    }

    auto root() const noexcept -> const node_type*
    {
        return root_.get();
    }

private:
    static auto insert(std::unique_ptr<node_type>& node, T&& data) -> void
    {
        if (!node) {
            node = make_node(std::move(data));
        } else {
            if (data <= node->data_) {
                insert(node->left_, std::move(data));
            } else {
                insert(node->right_, std::move(data));
            }
        }
    }

    static auto make_node(T&& data) -> std::unique_ptr<node_type>
    {
        return std::unique_ptr<node_type>{new node_type{std::move(data)}};
    }

private:
    std::unique_ptr<node_type> root_;
};

#endif
