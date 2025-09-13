/*
1. '+', '-' is okay we can go from left to right check for k, ex: 432 => 4 - 3 + 2
2. but in case of '*' game begins here, ex: 432 => 4 - 3 * 2
3. above we can't go from left to right directly checking as we have to follow BODMAS
4. so how to track this '*' ?
5. we will maintain a lastNumber var in argument and valSoFar which will tell the val we go so far from left to right and the last number which we added(subtraction case implicitly handled by -ve sign)
6. so in case we go for '*', we will do this => valSoFar - lastNumber + lastNumber * currNumber
7. ex: valSoFar = 8, lastNumber = 3, currNumber = 2, 532, 5 + 3 * 2
    8 - 3 + 3 * 2 => 5 + 3 * 2
*/


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp;

        solve(num, temp, 0, 0, 0, target, ans);

        return ans;
    }

private:
    void solve(string& num, string& temp, int start, long long valSoFar,
               long long lastNumber, int k, vector<string>& ans) {

        if (start >= num.size()) {
            if (valSoFar == static_cast<long long>(k))
                ans.push_back(temp);
            return;
        }

        for (int i = start; i < num.size(); i++) {
            const long long number = convertToInteger(num, start, i);
            const string& stringifiedNumber = num.substr(start, i - start + 1);

            // skipping number with leading zeros
            if (i > start && num[start] == '0')
                break;

            if (start == 0) {
                temp.append(stringifiedNumber);
                solve(num, temp, i + 1, number, number, k, ans);
                popNTimes(temp, stringifiedNumber.size());
                continue;
            }

            // check for *
            if (number == 0 || (lastNumber <= INT_MAX / number &&
                                lastNumber >= -INT_MAX / number)) {
                int currVal = valSoFar - lastNumber + lastNumber * number;
                temp.append("*" + stringifiedNumber);
                solve(num, temp, i + 1, currVal, lastNumber * number, k, ans);
                popNTimes(temp, stringifiedNumber.size() + 1);
            }

            // check for +
            temp.append("+" + stringifiedNumber);
            solve(num, temp, i + 1, valSoFar + number, number, k, ans);
            popNTimes(temp, stringifiedNumber.size() + 1);

            // check for -
            temp.append("-" + stringifiedNumber);
            solve(num, temp, i + 1, valSoFar - number, -number, k, ans);
            popNTimes(temp, stringifiedNumber.size() + 1);
        }
    }

    long long convertToInteger(const string& strnum, int start, int end) {
        long long number = 0;
        long long place = 1;
        for (int i = end; i >= start; i--, place *= 10) {
            number += (strnum[i] - '0') * place;
        }

        return number;
    }

    void popNTimes(string& str, int n) { str.erase(str.size() - n); }
};