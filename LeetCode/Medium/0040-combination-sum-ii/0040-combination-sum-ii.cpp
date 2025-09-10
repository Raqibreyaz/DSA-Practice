/*
1. to avoid duplicates let's sort the vector
2. when considering candidates[i] exceeds k then considering candidates[i+1] or so on will too exceed k so skip them early
3. instead of making 2 recursive calls for considering and not considering
4. loop over candidates and each time compute by considering candidates[i] 
5. this way we can find out, did we computed using this value before? as starting will be changed
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(candidates.begin(),candidates.end());

        solve(candidates,0,target,temp,ans);

        return ans;
    }

private:
    void solve(vector<int>& candidates,int start, int k, vector<int>& temp, vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = start; k > 0 && i < candidates.size(); i++){

            // when starting changed then check if this candidated is already considered previously
            if(i > start && candidates[i] == candidates[i-1])
                continue;

            temp.push_back(candidates[i]);
            solve(candidates,i+1,k - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
};