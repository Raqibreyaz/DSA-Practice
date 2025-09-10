/*
1. sort to keep track of duplicates
2. traverse entire array
3. take nums[i] generate all subsets from it
4. then take nums[i+1] generate all subsets from it
5. so on
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sorting to know duplicates
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);

        return ans;
    }

private:
    void solve(vector<int>& nums, int start, vector<int>& temp,
               vector<vector<int>>& ans) {
        for (int i = start; i < nums.size(); i++) {

            // skip when already computed
            if(i > start && nums[i] == nums[i-1])
                continue;

            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }

        // take the generated subset till start
        ans.push_back(temp);
    }
};