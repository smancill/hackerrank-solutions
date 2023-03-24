// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <functional>
#include <iostream>
#include <stack>
#include <string>


class TextEditor
{
public:
    auto append(const std::string& s) -> void
    {
        append_impl(s);
        undo_.push([this, k=s.size()] { delete_last_impl(k); });
    }

    auto delete_last(int k) -> void
    {
        auto s = delete_last_impl(k);
        undo_.push([this, s=std::move(s)] { append_impl(s); });
    }

    auto undo() -> void
    {
        auto& f = undo_.top();
        f();
        undo_.pop();
    }

    auto operator[](int k) const noexcept -> char
    {
        return text_[k - 1];
    }

private:
    auto append_impl(const std::string& s) -> void
    {
        text_ += s;
    }

    auto delete_last_impl(int k) -> std::string
    {
        auto n = text_.size() - k;
        auto deleted = text_.substr(n);
        text_.resize(n);
        return deleted;
    }

private:
    std::string text_;
    std::stack<std::function<void()>> undo_;
};


auto main() -> int
{
    int q;
    std::cin >> q;

    auto e = TextEditor{};

    while (q-- > 0) {
        int op;
        std::cin >> op;

        if (op == 1) {
            std::string w;
            std::cin >> w;
            e.append(w);
        } else if (op == 2) {
            int k;
            std::cin >> k;
            e.delete_last(k);
        } else if (op == 3) {
            int k;
            std::cin >> k;
            std::cout << e[k] << '\n';
        } else if (op == 4) {
            e.undo();
        }
    }

    return 0;
}
