/*

1. every number n > 1 can be divided by 2, 3 & 5
2. if not divisible by 2,3 & 5 then n itself is prime or it has prime factors > n
3. n = 60,  2 * 2 * 3 * 5 = LCM(n) => ugly , because each factor is {2,3,5}
4. n = 77, 7 * 11 = LCM(n) => !ugly
5. n = 111, 3 * 37 = LCM(n) => !ugly
6. so we have to peform iteration to reduce {2,3,5} each time and > 5 prime will itself come

*/

class Solution {
public:
    bool isUgly(int n) {

        while (n > 1) {

            if (n % 2 == 0) {
                n = n / 2;
            } else if (n % 3 == 0) {
                n = n / 3;
            } else if (n % 5 == 0) {
                n = n / 5;
            } else
                return false;
        }

        return n == 1;
    }
};