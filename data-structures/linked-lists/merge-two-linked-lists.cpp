// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>


template<typename T>
class List {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
    };

public:
    using value_type = T;

    List() = default;

    List(const List&) = delete;
    auto operator=(const List&) -> List& = delete;

    List(List&&) = default;
    auto operator=(List&&) -> List& = default;

    ~List()
    {
        while (head) {
            head = std::move(head->next);
        }
    }

    auto push_back(const T& elem) -> void
    {
        if (*tail) {
            tail = &(*tail)->next;
        }
        *tail = std::make_unique<Node>(elem);
    }

    auto print(std::ostream& os) const -> std::ostream&
    {
        auto* ptr = &head;
        while (*ptr) {
            os << (*ptr)->data << ' ';
            ptr = &(*ptr)->next;
        }
        return os;
    }

    std::unique_ptr<Node> head;
    decltype(head)* tail = &head;
};


template<typename T>
auto operator>>(std::istream& is, List<T>& list) -> std::istream&
{
    int n;
    is >> n;
    std::copy_n(std::istream_iterator<T>{is}, n, std::back_inserter(list));
    return is;
}


template<typename T>
auto operator<<(std::ostream& os, List<T>& list) -> std::ostream&
{
    return list.print(os);
}


template<typename T>
auto merge_lists(List<T>&& list1, List<T>&& list2) -> List<T>
{
    auto merged = List<T>{};
    auto head1 = std::move(list1.head);
    auto head2 = std::move(list2.head);
    auto* current = decltype(&merged.head){};

    // merge nodes
    while (head1 && head2) {
        auto* ptr = head1->data <= head2->data ? &head1 : &head2;
        if (!merged.head) {
            merged.head = std::move(*ptr);
            current = &merged.head;
        } else {
            (*current)->next = std::move(*ptr);
            current = &(*current)->next;
        }
        *ptr = std::move((*current)->next);
    }
    auto* ptr = head1 ? &head1 : &head2;
    (*current)->next = std::move(*ptr);

    // fix tail
    while ((*current)->next) {
        current = &(*current)->next;
    }
    merged.tail = current;
    list1.tail = nullptr;
    list2.tail = nullptr;

    return merged;
}


auto main() -> int
{
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        auto list1 = List<int>{};
        auto list2 = List<int>{};

        std::cin >> list1 >> list2;

        auto merged = merge_lists(std::move(list1), std::move(list2));

        std::cout << merged << '\n';
    }

    return 0;
}
