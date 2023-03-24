// SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
//
// SPDX-License-Identifier: MIT-0

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using Edges = std::vector<std::vector<int>>;
using Graph = std::vector<std::set<int>>;


auto make_graph(int nodes, const Edges& edges) -> Graph
{
    auto graph = Graph(nodes);
    for (const auto& e : edges) {
        auto u = e[0] - 1;
        auto v = e[1] - 1;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    return graph;
}


auto min_dist(int nodes, const Edges& edges, int start) -> std::vector<int>
{
    constexpr auto edge_length = 6;

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
                dist[node] = dist[current] + edge_length;
                queue.push(node);
                visited.insert(node);
            }
        }
    }
    dist.erase(dist.begin() + start);

    return dist;
}


auto read_edges(int m) -> Edges
{
    auto edges = Edges{};
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        edges.push_back({u, v});
    }
    return edges;
}


auto main() -> int
{
    int q;
    std::cin >> q;

    while (q-- > 0) {
        int n, m;
        std::cin >> n >> m;

        auto edges = read_edges(m);

        int s;
        std::cin >> s;

        auto dist = min_dist(n, edges, s);

        for (auto d : dist) {
            std::cout << d << ' ';
        }
        std::cout << '\n';
    }
}
