class Solution {
public:
    string largestOddNumber(string num) {
        int j;
        for( j = num.length()-1; j >= 0; j--){
            int n = num[j] - '0';            
            if(n % 2 != 0)
                break;
        }

        return num.substr(0,j+1);
    }
};