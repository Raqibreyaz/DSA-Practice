/*
1st approach (Hashmap + Vector):
    - count frequency in unordered map
    - copy them in a vector
    - now sort the vector according to the frequency
    - TC = O(N) , SC = O(1)

2nd approach (Hashmap + priority_queue):
    - count frequency in unordered_map
    - store all freq pairs in a priority queue acording to freq
    - pop each time and write chars to string
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(const char& ch: s){
            freq[ch]++;
        }

        priority_queue<pair<char,int>> freqPQ;
        
        // storing every char with frequency
        for(const auto&[ch,f]: freq){
            freqPQ.push({f,ch});
        }

        for(int i = 0; !freqPQ.empty();){
            const auto& [f,ch] = freqPQ.top();

            // putting the char 'freq' times
            for(int  j = f; j > 0; j--,i++)
                s[i] = ch;

            freqPQ.pop();
        }

        return s;
    }
};