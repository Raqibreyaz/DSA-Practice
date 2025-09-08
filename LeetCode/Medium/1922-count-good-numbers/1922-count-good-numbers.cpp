class Solution {
public:
    int countGoodNumbers(long long n) {
       int modulo = 1e9+7;

       long long evenIndices = (n+1) / 2;
       long long oddIndices = n / 2;

       long evenSide = findPower(5,evenIndices);
       long oddSide = findPower(4,oddIndices);

       return static_cast<int>((evenSide * oddSide) % modulo);
    }

private:
    int findPower(const long long a,const long long b){

        if(b == 0)
            return 1;
        if(b == 1)
            return a;

        long long half = findPower(a,b/2);
        long long full = (half * half) % modulo;

        if(b & 1)
            full = (full * a ) % modulo;
        
        return static_cast<int>(full);
    }

    const int modulo = 1e9+7;
};