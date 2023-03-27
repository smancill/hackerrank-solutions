// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <vector>


struct Edge {
    int u;
    int v;

    constexpr static auto weight = 6;
};


auto operator>>(std::istream& is, Edge& e) -> std::istream&
{
    return is >> e.u >> e.v;
}


using Edges = std::vector<Edge>;
using Graph = std::vector<std::set<int>>;


auto make_graph(int nodes, const Edges& edges) -> Graph
{
    auto graph = Graph(nodes);
    for (auto [u, v] : edges) {
        u -= 1;
        v -= 1;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    return graph;
}


auto min_dist(int nodes, const Edges& edges, int start) -> std::vector<int>
{
    auto graph = make_graph(nodes, edges);

    auto dist = std::vector<int>(nodes, -1);
    auto queue = std::queue<int>{};
    auto visited = std::set<int>{};

    dist[--start] = 0;
    queue.push(start);
    visited.insert(start);

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();
        for (auto node : graph[current]) {
            if (!visited.contains(node)) {
                dist[node] = dist[current] + Edge::weight;
                queue.push(node);
                visited.insert(node);
            }
        }
    }
    dist.erase(dist.begin() + start);

    return dist;
}


auto main() -> int
{
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; ++i) {
        int n;
        std::cin >> n;

        int m;
        std::cin >> m;

        auto edges = Edges{};
        edges.reserve(m);
        std::copy_n(std::istream_iterator<Edge>{std::cin}, m,
                    std::back_inserter(edges));

        int s;
        std::cin >> s;

        auto dist = min_dist(n, edges, s);

        for (auto d : dist) {
            std::cout << d << ' ';
        }
        std::cout << '\n';
    }
}
