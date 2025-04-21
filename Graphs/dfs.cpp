#include <iostream>
#include <vector>
#include <unordered_map>
#include "../utils/utils.cpp"

void printDFS(std::unordered_map<int, std::vector<int>> &graph,
              std::vector<bool> &visited,
              int node)
{
    if (visited[node])
        return;

    std::cout << node << " " << std::endl;

    visited[node] = true;

    for (auto &nbr : graph[node])
    {
        if (visited[nbr])
            continue;

        printDFS(graph, visited, nbr);
    }
}

void DFS(std::unordered_map<int, std::vector<int>> &graph)
{
    std::vector<bool> visited(graph.size(), false);

    for (auto &node : graph)
    {
        printDFS(graph, visited, node.first);
    }
}

int main(int argc, char const *argv[])
{
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 6, 5}},
        {3, {1, 4}},
        {4, {1, 3}},
        {5, {2}},
        {6, {2}},
    };

    DFS(graph);

    return 0;
}
