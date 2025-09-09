class Solution {
public:
    double myPow(double a, int b) {
        return solve(a,b);
    }

private:
    double solve(double a, long b) {
        if (b == 0)
            return 1;
        else if (b < 0) {
            return solve(1 / a, -b);
        } else if (b % 2 == 0)
            return solve(a * a, b / 2);
        return  a * solve(a * a, b / 2);
    }
};