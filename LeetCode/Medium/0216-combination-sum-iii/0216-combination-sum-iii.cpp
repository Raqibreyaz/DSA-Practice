/*
1. we have 9 choices, digits 1 to 9
2. each number must be used only once in a combination
3. => loop over 9 choices
4. find answers considering i then find answers skipping i
5. when k == 0 && n == 0 means an answer found
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,1,temp,ans);

        return ans;
    }

private:
    void solve(int n, int k, int start,vector<int>& temp,vector<vector<int>>& ans){
        
        // when a subset of length k and sum n found then keep it
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i <= 9; i++){
            temp.push_back(i);
            solve(n-i,k-1, i + 1,temp,ans);
            temp.pop_back();
        }
    }
};