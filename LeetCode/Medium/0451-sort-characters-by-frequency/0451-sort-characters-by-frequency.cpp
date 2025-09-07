/*
1st approach (Hashmap + Vector):
    - count frequency in unordered map
    - copy them in a vector
    - now sort the vector according to the frequency
    - TC = O(N) , SC = O(1)

2nd approach (Hashmap + priority_queue):

*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(const char& ch: s){
            freq[ch]++;
        }

        vector<pair<char,int>> freqVector(freq.begin(),freq.end());
        
        sort(freqVector.begin(),freqVector.end(),[](const auto& p1,const auto& p2){
            return p1.second > p2.second;
        });

        int i = 0;
        for(const auto& [ch,freq]: freqVector){
            
            // putting the char 'freq' times
            for(int  j = freq; j > 0; j--)
                s[i++] = ch;
        }

        return s;
    }
};