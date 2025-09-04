class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        // storing product for every (0,i) skipping 0
        vector<int> prefixProduct(nums.size(),0);
        for(int i = 0; i < nums.size(); i++){

            int previousProd = 1;
            
            if(i > 0 && prefixProduct[i-1] != 0)
                previousProd = prefixProduct[i-1];

            prefixProduct[i] = previousProd * nums[i];
        }

        // storing product of every (i,n) skipping 0
        vector<int> suffixProduct(nums.size(),0);
        for(int i = nums.size()-1; i >= 0; i--){

            int previousProd = 1;
            
            if(i < suffixProduct.size() -1 && suffixProduct[i+1] != 0)
                previousProd = suffixProduct[i+1];

            suffixProduct[i] = previousProd * nums[i];
        }


        int maxProduct = -INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int prefix = prefixProduct[i];
            int suffix = suffixProduct[i];

            maxProduct = max({maxProduct,prefix,suffix});
        }

        return maxProduct;
    }
};