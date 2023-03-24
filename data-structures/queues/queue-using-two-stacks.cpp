// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <stack>


template<typename T>
class Queue {
public:
    auto enqueue(T elem) -> void
    {
        enq_stack_.push(std::move(elem));
    }

    auto dequeue() -> T
    {
        move_items();
        auto front = std::move(deq_stack_.top());
        deq_stack_.pop();
        return front;
    }

    auto front() -> T&
    {
        move_items();
        return deq_stack_.top();
    }

private:
    auto move_items() -> void
    {
        if (deq_stack_.empty()) {
            while (!enq_stack_.empty()) {
                deq_stack_.push(std::move(enq_stack_.top()));
                enq_stack_.pop();
            }
        }
    }

private:
    std::stack<T> enq_stack_;
    std::stack<T> deq_stack_;
};


auto main() -> int
{
    int n;
    std::cin >> n;

    auto q = Queue<int>{};

    for (auto i = 0; i < n; ++i) {
        int op;
        std::cin >> op;
        switch (op) {
            case 1:
                int item;
                std::cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                std::cout << q.front() << '\n';
                break;
        }
    }

    return 0;
}
