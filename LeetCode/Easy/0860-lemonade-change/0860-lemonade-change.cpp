/*

1. for 5 we dont have to return anything
2. for 10 we have to return 10 - 5 = 5 denomination
3. for 20 we have to return 20 - 5 = 15 denomination
ex: 15 can be returned in 2 ways:
    - 5 * 3
    - 10 + 5
4. we will maintain 3 vars for the count denominations of 5,10,20

*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5 = 0;
        int d10 = 0;
        int d20 = 0;

        for (const int& bill : bills) {
            int change = bill - 5;

            if (change == 0) {
                d5++;
                continue;
            }

            else if (change == 5) {
                if (d5 > 0)
                    d5--;
                else
                    return false;

                d10++;
            } else {
                if (d5 >= 1 && d10 >= 1) {
                    d5 -= 1;
                    d10 -= 1;
                } else if (d5 >= 3) {
                    d5 -= 3;
                }

                else
                    return false;

                d20++;
            }
        }

        return true;
    }
};