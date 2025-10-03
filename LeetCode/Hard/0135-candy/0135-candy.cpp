/*

Brute:
T.C = O(N), A.S = O(N)
- since all children will get at least a candy, then assign 1 candy to each child initially
- perform 2 passes, from L to R then R to L
- for L to R, check if current child's rating > previous child's, if yes then increase counter by 1 + previous child's candies
- similarly, for R to L, check if current child's rating > right child's, if yes then increase counter by 1 + right child's candies

Optimal: 
T.C= O(N), A.S  = O(1)
[1,2,5,7,8,4,2,5,2,2]

    x + 4       8
  x + 3      7 / \
 x + 2      5 /   \      5  
x+1        2 /  x+1\4   / \
x         1 /   x+2 \2 /   \2_ _2

for 1 mountain(peak + dip):
candy = 10(1 for everyone)  + 1 + 2 + 3 + 4 + 1 + 2
candy -= min(peak, dip)

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // each child will get at least 1 candy
        int candy = n;

        for(int i = 1; i < n;){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // Increasing Slope
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;

                if(i == n)
                    return candy;
            }

            // Decreasing Slope
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peak,dip);
        }

        return candy;
    }
};