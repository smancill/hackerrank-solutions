// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0
//
// Based on the code provided in HackerRank by Vatsal Chanana

#ifndef HUFFMAN_TREE_HPP_
#define HUFFMAN_TREE_HPP_

#include <algorithm>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>


class HuffmanTree;


class HuffmanNode {
private:
    friend HuffmanTree;

    using pointer = std::unique_ptr<HuffmanNode>;

    HuffmanNode(char data, int freq, pointer left = {}, pointer right = {})
      : data_{data}, freq_{freq}, left_{std::move(left)}, right_{std::move(right)}
    {}

public:
    auto data() const -> char
    {
        return data_;
    }

    auto left() const noexcept -> const HuffmanNode*
    {
        return left_.get();
    }

    auto right() const noexcept -> const HuffmanNode*
    {
        return right_.get();
    }

private:
    char data_;
    int freq_;
    pointer left_;
    pointer right_;
};


class HuffmanTree {
public:
    HuffmanTree(std::string_view s)
      : root_{make_huffman(s)}, str_{encode(root_, s)}
    {}

    auto str() const noexcept -> const std::string&
    {
        return str_;
    }

    auto root() const noexcept -> const HuffmanNode*
    {
        return root_.get();
    }

private:
    using node_ptr = HuffmanNode::pointer;

    static auto make_huffman(std::string_view s) -> node_ptr
    {
        auto cmp = [](const node_ptr& a, const node_ptr& b) {
            return a->freq_ > b->freq_;
        };

        auto nodes = std::vector<node_ptr>{};
        auto count = std::vector<int>(256);

        for (auto c : s) {
            ++count[c];
        }

        for (auto i = 0; i < 256; ++i) {
            if (count[i] > 0) {
                nodes.push_back(make_node(static_cast<char>(i), count[i]));
                std::push_heap(nodes.begin(), nodes.end(), cmp);
            }
        }

        while (nodes.size() > 1) {
            std::pop_heap(nodes.begin(), nodes.end(), cmp);
            auto left = std::move(nodes.back());
            nodes.pop_back();

            std::pop_heap(nodes.begin(), nodes.end(), cmp);
            auto right = std::move(nodes.back());
            nodes.pop_back();

            auto freq = left->freq_ + right->freq_;
            auto combined = make_node('\0', freq, std::move(left), std::move(right));

            nodes.push_back(std::move(combined));
            std::push_heap(nodes.begin(), nodes.end(), cmp);
        }

        return std::move(nodes.back());
    }

    static auto encode(const node_ptr& root, std::string_view s) -> std::string
    {
        auto codes = std::map<char, std::string>{};

        encode(root, codes, "");

        auto encoded = std::ostringstream{};
        for (auto c : s) {
            encoded << codes[c];
        }
        return encoded.str();
    }

    static auto encode(const node_ptr& root,
                       std::map<char, std::string>& codes,
                       std::string code)
        -> void
    {
        if (!root) {
            return;
        }
        if (root->data_ != '\0') {
            codes[root->data_] = code;
        }
        encode(root->left_, codes, code + '0');
        encode(root->right_, codes, code + '1');
    }

    template <typename... Args>
    static auto make_node(Args&&... args) -> node_ptr
    {
        return node_ptr{new HuffmanNode{std::forward<Args>(args)...}};
    }

private:
    node_ptr root_;
    std::string str_;
};

#endif
