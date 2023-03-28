// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>


class Trie {
    struct Node {
        bool word = false;
        std::map<char, std::unique_ptr<Node>> children;
    };

public:
    auto insert(std::string_view word) -> void
    {
        auto* current = root_.get();
        for (auto c : word) {
            auto& child = current->children[c];
            if (!child) {
                child = std::make_unique<Node>();
            }
            current = child.get();
        }
        current->word = true;
    }

    auto search(std::string_view word) const noexcept -> bool
    {
        auto* current = root_.get();
        for (auto c : word) {
            if (!current->children.contains(c)) {
                return false;
            }
            current = current->children[c].get();
            if (current->word) {
                return true;
            }
        }
        return true;
    }

private:
    std::unique_ptr<Node> root_ = std::make_unique<Node>();
};


auto no_prefix(std::span<const std::string> words) -> void
{
    auto trie = Trie{};
    for (const auto& word : words) {
        if (trie.search(word)) {
            std::cout << "BAD SET\n" << word << '\n';
            return;
        }
        trie.insert(word);
    }
    std::cout << "GOOD SET" << '\n';
}


auto main() -> int
{
    int n;
    std::cin >> n;

    auto words = std::vector<std::string>{};
    std::copy_n(std::istream_iterator<std::string>{std::cin}, n,
                std::back_inserter(words));

    no_prefix(words);

    return 0;
}
