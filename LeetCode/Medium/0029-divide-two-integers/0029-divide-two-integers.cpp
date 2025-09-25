/*
divisor = 5, dividend = 53

Brute:
- how many times can i remove divisor from dividend so that dividend !< 0 =
quotient
- so loop and each time subtract divisor from dividend until you can't
- and keep counting

Optimal:
- instead of subtracting linearly each time
- increase divisor exponentially to reduce T.C
- each time increase divisor by *2 + keep counting using the power of 2 used
- count will be, 5 * 2 ^ 3 => count  = 3 (so far)
- since we can't use * here so we will do << (left shift)
*/

class Solution {
public:
    int divide(int dnd, int dvsr) {

        if (dnd == dvsr)
            return 1;
        
        if(dnd == 0)
            return 0;

        bool isPositive =
            (dnd < 0 ==
             dvsr < 0); // if both are of same sign, answer is positive

        unsigned int dividend = labs(1LL * dnd);
        unsigned int divisor = labs(1LL * dvsr);
        
        unsigned int ans = 0;
        while (dividend >= divisor) { // while dividend is greater than or equal to divisor
            int q = 0;
            while (dividend > (divisor << (q + 1)))
                q++;
            ans += (1 << q); // add the power of 2 found to the answer
            dividend = dividend -
                (divisor << q); // reduce the dividend by divisor * power of 2 found
        }
        
        // if ans cannot be stored in signed int
        if (ans == (1 << 31) && isPositive)
            return INT_MAX;
        
        return isPositive ? ans : -ans;
    }
};