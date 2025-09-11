/*
2 -> [a,b,c]
3 -> [d,e,f]
"23" -> [a,b,c] x [d,e,f]
=> ad, ae, af, bd, be, bf, cd, ce, cf
*/ 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        solve(digits,0,temp,ans);

        return ans;
    }

private:

    void solve(const string &digits,int index,string& temp, vector<string>& ans){

        if(index >= digits.size()){

            if(!temp.empty())
                ans.push_back(temp);

            return;
        }

        // generating combinations for all possibilities
        for(const char ch: mapping.at(digits[index])){
            temp.push_back(ch);
            solve(digits,index+1,temp,ans);
            temp.pop_back();
        }
    }

    const unordered_map<char, vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };
};