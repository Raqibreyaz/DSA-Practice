/*

BRUTE:
1. do whatever question is asking
2. we will try to break at each index so that each parititioned word exists in dictionary
3. if no combination exists then will return false
ex: "applepenapple", dict = ["apple","pen"]
    => partitions = ["apple","pen","apple"]

MEMO:
1. at each index we are trying to partition so that words exists in dictionary
2. but also we are wasting time over recalculating answer, like here:
   
            ex: applepenapple
                a/   ap|   \ ...
    pplepenaple   plepenapple(repeating)
   p/              
  plepenapple(repeating)

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> isWordPresent;
        for(const auto& word:wordDict){
            isWordPresent.insert(word);
        }
        
        memset(t,-1,sizeof(t));
       
        return solve(s, isWordPresent, 0);
    }

private:

    bool solve(const string& s, const unordered_set<string> &isWordPresent, int start){

        // empty string always present
        if(start >= s.size()) return true;

        if(t[start] != -1)
            return t[start];

        for(int i = start; i < s.size(); i++){
            const string& sstr = s.substr(start, i - start +1);
            if(isWordPresent.contains(sstr) && solve(s, isWordPresent, i+1))
                    return t[start] = true;
        }

        return t[start] = false;
    }

    int t[300];
};