/*

1. lets say you got k = 5 char to return
2. means at least len = 8 required! (because len is a multiple of 2)
ex: "aaaa", op = 0 => "aaaaaaaa", it means that str[0] == str[len/2 + 1]
ex: "aaaa", op = 1 => "aaaabbbb", it means that str[0] == str[len/2 + 1] + 1
3. so we can say that str[k] at length l == str[k - l/2] at length l/2
4. also length depends on k, we can't say decrease l/2 and k - l/2 each time
5. for each k  we have to calculate length
6. for proof, check this: k = 10 and len = 16, and each time decrease len/2 and k - len/2, here k will go < 0

*/

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        if(k == 1)
            return 'a';

        int nOperations = operations.size();
        long long len = 1;
        int operationType = -1;

        // O(logK)
        for(int i = 0; i < nOperations; i++){
            len *= 2;

            if(len >= k){
                operationType = operations[i];
                break;
            }
        }

        // O(logK)
        // get the (k - len/2)th char
        char ch = kthCharacter(k - len / 2,operations);

        if(operationType == 0){
            return ch;
        }
        
        return ch == 'z' ? 'a' : ch + 1;
    }
};