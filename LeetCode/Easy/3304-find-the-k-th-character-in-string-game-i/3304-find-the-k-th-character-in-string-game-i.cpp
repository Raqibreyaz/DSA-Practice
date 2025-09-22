/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
a b b c b c c d b c c  d  c  d  d  e

- when k = 2^x, str[2^x - 1] = 'a' + (x - 1)
- k = 16, index = 15, 15 = 1111 => 'a' + 4 = 'e'
- k = 13, index = 12, 12 = 1100 => 'a' + 2 = 'c'

*/


class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + countNoOfBits(k-1);
    }

private:
    int countNoOfBits(int x){
        
        int count = 0;
        
        while(x > 0){
            count += (x & 1);

            x = (x >> 1);
        }

        return count;
    }
};