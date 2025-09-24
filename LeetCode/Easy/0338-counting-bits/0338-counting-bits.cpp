class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.reserve(n+1);

        for(int i = 0; i <= n; i++){
            ans.push_back(countOfSetBits(i));
        }

        return ans;
    }

private:

    // O(log(x))
    int countOfSetBits(int x){
        int count = 0;
        while(x > 0){
            x = x & (x-1);
            count++;
        }
        return count;
    }
};