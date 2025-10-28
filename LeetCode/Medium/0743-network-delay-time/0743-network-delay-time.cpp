/*

1. simple BFS
2. propagate the signal
3. each signal propagation time is cumulative sum of time in the path

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph(n);
        for(const auto& edge: times){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }

        set<pair<int,int>>st;
        vector<int> result(n+1,INT_MAX);

        st.insert({k,0});
        result[k] = 0;

        while(!st.empty()){
            auto it = st.begin();
            const int node = it->first;
            const int timeSoFar = it->second;
            st.erase(it);

            for(const auto& [nbr,time]: graph[node]){

                // when we got better answer then remove previous one and add new one
                if(result[nbr] > (time + timeSoFar)){

                    // we got better answer to skip the longer timing
                    st.erase({nbr,result[nbr]});

                    // update the new time and add it set
                    result[nbr] = time + timeSoFar;               
                    st.insert({nbr,result[nbr]});
                }
            }
        }

        int maxi = INT_MIN;

        // if the signal failed to reach any node
        for(int i = 1; i <= n; i++){
            if(result[i] == INT_MAX)
                return -1;

            maxi = max(maxi,result[i]);
        }

        return maxi;
    }
};