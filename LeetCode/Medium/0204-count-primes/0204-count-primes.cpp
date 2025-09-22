class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<bool> isPrime(n,true);

        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < n; i++){
            for(int j = 2; i * j < n; j++){
                isPrime[i * j] = false;
            }
        }

        int count = 0;
        for(const bool& p: isPrime){
            if(p) count++;
        }

        return count;
    }
};