class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // creating graph, u -> v, cost = d
        vector<vector<pair<int,int>>> graph(n);
        for(const auto& edge: flights){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }

        vector<int> result(n,INT_MAX);
        queue<pair<int,int>> q;

        int level = 0;
        q.push({src,0});

        // we will consider nodes level by level
        while(!q.empty() && level <= k){
            const int& N = q.size();

            // considering all the nodes of current level
            for(int i = 0; i < N; i++){
                const auto& [node,costSoFar] = q.front();

                // update cost, when less cost exist
                for(const auto& [nbr, cost]: graph[node]){
                    if(result[nbr] > (costSoFar + cost)){
                        result[nbr] = costSoFar + cost;
                        q.push({nbr,result[nbr]});
                    }
                }

                q.pop();
            }
            level++;
        }

        return result[dst] == INT_MAX ? -1: result[dst];
    }
};