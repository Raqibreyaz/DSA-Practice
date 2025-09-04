/*
p + q + r + s = target
=> p + q = target - (r + s)
=> so we will apply 2 sum strategy where fixing r and s we will find p and q
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int p = 0; p < nums.size(); p++){

            if(p > 0 && nums[p] == nums[p-1])
                continue;

            for(int q = p+1; q < nums.size();){

                long long currTarget = (long long)target - ((long long)nums[p] + (long long)nums[q]);

                int r = q +1, s = nums.size()-1;
                while(r < s){
                    long long sum = nums[r] + nums[s];
                    if(sum == currTarget){
                        ans.push_back({nums[p],nums[q],nums[r],nums[s]});
                        r++;
                        s--;

                        // skipping duplicate if already process same number
                        while(r < s && nums[r] == nums[r-1])
                            r++;
                    }
                    else if(sum < currTarget){
                        r++;
                    }
                    else{
                        s--;
                    }
                }

                q++;

                // when already process for same number 
                // skip duplicate
                while(q < nums.size() && nums[q] == nums[q-1])
                    q++;
            }
        }

        return ans;
    }
};