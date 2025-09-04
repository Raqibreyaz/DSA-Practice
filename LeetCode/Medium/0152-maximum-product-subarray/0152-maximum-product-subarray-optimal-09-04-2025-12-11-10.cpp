class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1, maxProduct = -INT_MAX;

        for(int  i = 0; i < nums.size(); i++){
            
            // when prefix becomes 0 we will skip the previous subarray
            // and start from here
            if(prefix == 0)
                prefix = 1;
            
            prefix = prefix * nums[i];
            maxProduct = max(maxProduct ,prefix);
        }

        for(int  j = nums.size() -1; j >=0 ; j--){

            // when suffix becomes 0 we will skip the previous subarray 
            // and start from here
            if(suffix == 0)
                suffix = 1;
            
            suffix = suffix * nums[j];
            maxProduct = max(maxProduct, suffix);
        }

        return maxProduct;
    }
};