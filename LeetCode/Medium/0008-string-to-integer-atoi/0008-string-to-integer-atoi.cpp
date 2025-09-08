/*

1. skip leading whitespace if present
2. skip '+' or '-' if present
3. read digits until a non-digit is encountered
4. dont go further if you find a non-digit char after step 2 and return 0
5. if answer goes < -INT_MAX then return -INT_MAX
6. if answer goes > INT_MAX then return INT_MAX
*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int number = 0;
        int sign = 1;

        // skipping leading whitespace
        while(i < s.length() && s[i] == ' ') i++;

        if(i < s.length() && s[i] == '+' || s[i] == '-'){
            if(s[i] == '-')
                sign = -1;
            i++;
        } 

        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            
            int digit = s[i] - '0';

            if(number > (INT_MAX - digit) / 10)
                return sign == -1 ? -INT_MAX-1 : INT_MAX;
                
            number = number * 10 + digit;
            
            // returning rounded value when number goes out of range

            i++;
        }

        return sign * number;
    }
};