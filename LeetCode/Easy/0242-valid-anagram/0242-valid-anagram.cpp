/*
1st approach (simple array):
    - s  = anagram of t
    - t = anagram of t
    - when chars frequency are equal in both

2nd approach (hashmap in case of unicode chars):
    - since unicode chars can have all valid chars ~1.1 million so not possible 
      to use array (include emojis, urdu char, arabi char, hindi char etc.)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // 2 strings can never be anagram of each other 
        // if no of chars are !=
        if(s.size() != t.size())
            return false;
        
        unordered_map<char32_t,int> sFreq;
        unordered_map<char32_t,int> tFreq;

        for(const char32_t& ch: s){
            sFreq[ch]++;
        }
        for(const char32_t& ch: t){
            tFreq[ch]++;
        }

        for(const auto& [ch,freq]: sFreq){
            if(!tFreq.contains(ch) || tFreq[ch] != freq)
                return false;
        }
        for(const auto& [ch,freq]: tFreq){
            if(!sFreq.contains(ch) || sFreq[ch] != freq)
                return false;
        }

        return true;
    }
};