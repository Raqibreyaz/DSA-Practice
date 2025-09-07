class Solution {
public:
    int maxDepth(string s) {
        int maxiDepth = 0;
        int currDepth = 0;

        for(const char& ch: s){
            if(ch == '(')
                currDepth++;
            else if(ch == ')')
                currDepth--;

            maxiDepth = max(maxiDepth,currDepth);
        }
        return maxiDepth;
    }
};