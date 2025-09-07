/*
1. when s[i] < s[i+1] => s[i+1] - s[i] , ex: CM => 1000 - 100 = 900
2. when s[i] > s[i+1] => s[i] , ex: MC => 1000
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanMapping = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        int finalNumber = 0;

        for(int i = 0; i < s.length(); i++){

            // subtraction case
            if(i < s.length() -1 && romanMapping[s[i]] < romanMapping[s[i+1]]){
                finalNumber += romanMapping[s[i+1]] - romanMapping[s[i]];
                i++;
            }

            // normal case
            else{
                finalNumber += romanMapping[s[i]];
            }
        }

        return finalNumber;
    }
};