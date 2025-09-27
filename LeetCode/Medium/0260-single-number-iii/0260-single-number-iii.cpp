/*

Brute:
- count frequency of all the numbers
- then take only those numbers which are of frequency = 1

Optimal:
- what if we XOR ? all elements will cancel out each other and only a ^ b will left
- a ^ b != 0 (always)
- imagine if there's a way where we only have 1 unique number
- then we could easily find it by doing a single XOR operation
- what if we have 2 groups where each group has exact 1 unique number and all other are elements will be duplicates
- through this grouping we can easily XOR out all duplicates and only unique ones will left in each group
ex: [2,1,3,1,3,4,4,7,6,6] => [1,1,2,3,3] , [4,4,7,6,6] => [2] , [7]
- But How ?
- a ^ b = c , where 'c' has difference bits means bits in both numbers which are different and doing XOR will keep it
- 3 = 0 1 1 
  5 = 1 0 1
------------
  6 = 1 1 0 

- build a mask = 1 << i (where i is the rightmost set bit in result)
- now doing nums[i] & mask, ensures that a and b can be easily differentiated
- mask = (a ^ b) & (-(a ^ b)) isolates the rightmost set-bit

*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long axorb = 0;
        for(const int &x: nums)
            axorb = axorb ^ x;

        // isolating the rightmost-set bit
        int mask = axorb & (-axorb);

        // creating 2 groups in which both numbers will be stored seperately
        int group1 = 0;
        int group2 = 0;

        for(const int& x: nums){
            if((x & mask) == 0)
                group2 = group2 ^ x;
            else group1 = group1 ^ x;
        }

        return {group1,group2};
    }
};