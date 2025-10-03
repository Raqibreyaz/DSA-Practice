/*

- since all children will get at least a candy, then assign 1 candy to each child initially
- perform 2 passes, from L to R then R to L
- for L to R, check if current child's rating > previous child's, if yes then increase counter by 1
- similarly, for R to L, check if current child's rating > right child's, if yes then increase counter by 1

*/


class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> assigned(ratings.size(),1);

        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1] && assigned[i] <= assigned[i-1])
                assigned[i] = assigned[i-1] + 1;
        }
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && assigned[i] <= assigned[i+1])
                assigned[i] = assigned[i+1] + 1;
        }
        
        int counter = 0;
        for(const int& x: assigned)
            counter += x;
        
        return counter;
    }
};