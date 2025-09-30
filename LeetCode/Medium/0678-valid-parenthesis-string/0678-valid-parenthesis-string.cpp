/*

Brute (Recursion):
- since '*' can be used for '(' and ')' and nothing, it means we have 3 options
- so we have to explore each option to get a true result in any of them or
return false
- T.C = O(3 ^ N) and O(N^2) with memoization

Bottom-Up(DP): if memoization possible then surely bottom-up can be done
- T.C = same as above with memo

Two Stacks:
- suppose we have a valid substring *_valid_substring_), where an asterisk
before it and a ')' left alone
- we will check if we have an asterisk before this ')', if yes then it can be
balanced
- when whole string is traversed, now see if any '(' left and asterisk left, if
yes then check if asterisk came after the '(' then it can be balanced otherwise
not possible

Left then Right approach:
- first start from left, for every '(' and '*' consider it as '(' and check if
running count goes < 0
- then start from rigth, for every ')' and '*' consider it as ')' and check if
running count goes < 0
- if any count goes < 0 then string is invalid
- but why this works ? just think about this:
    when considering all '(' and '*' as '(' and count goes < 0, it means that
')' are much more than '(' when considering all ')' and '*' as ')' and count
goes < 0, it means that '(' are much more than ')'
*/

class Solution {
public:
    bool checkValidString(string s) {
        int leftCount = 0;
        int rightCount = 0;

        for (const char& ch : s) {
            if (ch == '(' || ch == '*') {
                leftCount++;
            } else {
                leftCount--;
            }

            // it means ')' are much more than '('
            if (leftCount < 0)
                return false;
        }

        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                rightCount++;
            } else {
                rightCount--;
            }

            // it means '(' are much more than ')'
            if (rightCount < 0)
                return false;
        }

        return true;
    }
};