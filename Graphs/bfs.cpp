#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

void BFS(std::unordered_map<int, std::vector<int>> &graph)
{
    std::queue<int> que;
    std::vector<bool> visited(graph.size(), false);

    que.push(0);
    visited[0] = true;

    while (!que.empty())
    {
        int node = que.front();
        que.pop();

        std::cout << node << " ";

        for (auto &nbr : graph[node])
        {
            if (visited[nbr])
                continue;

            que.push(nbr);
            visited[nbr] = true;
        }
    }
    std::cout << std::endl;
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

    BFS(graph);
    return 0;
}
