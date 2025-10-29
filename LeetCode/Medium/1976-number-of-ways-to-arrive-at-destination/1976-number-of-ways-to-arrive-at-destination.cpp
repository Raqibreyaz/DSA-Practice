/*

vector<>dist; the minimum distance to reach that node from src
vector<>ways; the no of shortest ways to reach that node from src
dist[nbr], distance to reach neighbour from current node
wtSoFar, cumulative weight from src till current node
wt, weight to reach from current node to nbr

- least no of ways to reach node from src => ways[node] = ways[parent]

- when we got a shorter path then no of ways will
dist[nbr] > (wtSoFar + wt):
    ways[nbr] = ways[node]

- when we get the same shorter path then we got paths of 1 more node
dist[nbr] = (wtSoFar + wt):
    ways[nbr] = ways[nbr] + ways[node];

*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);

        // creating the graph
        for(const auto& edge: roads){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }

        // min distance to reach node from src
        vector<long long> dist(n,LLONG_MAX);

        // no of ways to reach node from src
        vector<int> ways(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        pq.push({0,0});
        ways[0] = 1;
        dist[0] = 0;

        while(!pq.empty()){
            const auto [wtSoFar,node] = pq.top();
            pq.pop();

            for(const auto& [nbr,wt]: graph[node]){
                if(dist[nbr] > (wtSoFar + wt)){
                    
                    dist[nbr] = wtSoFar + wt;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr], nbr});
                }
                else if(dist[nbr] == (wtSoFar + wt)){
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }

private:
    const long long mod = 1e9 + 7;
};


























