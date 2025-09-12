/*

1. for each index of the string we have two choices:
    - start a new partition
    - or add this in the previous paritition if is palindrome
2. but how to add in previous parition ? => use loop inside
3. so will run for loop for every index , keeping start and end index of current partition
4. when substring from start to end is a palindrome then go forward for next partition else skip this path
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;

        solve(s, 0, path,ans);

        return ans;
    }

private:
    void solve(const string& str, int start, vector<string>& path, vector<vector<string>>& ans){

        // since str exhausted means we got a palindrome partitioned path
        if(start >= str.size()){
            ans.push_back(path);
            return;
        }

        for(int i = start;i < str.size(); i++){

            // if this sstr is a palindrome then go forward for next partition
            if(isPalindrome(str,start,i)){

                // keeping in path for answer
                path.push_back(str.substr(start, i - start + 1));
                
                solve(str, i + 1, path,ans);

                // backtrack for next answer
                path.pop_back();
            }   
        }
    }

    bool isPalindrome(const string& str,int start, int end){
        for(int i = start,j = end; i < j; i++,j--){
            if(str[i] != str[j])
                return false;
        }

        return true;
    }
};