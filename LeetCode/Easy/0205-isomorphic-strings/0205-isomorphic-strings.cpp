class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> sHistory(128, 0);
        vector<char> tHistory(128, 0);

        for (int i = 0; i < s.length(); i++) {
            if (sHistory[s[i]] == t[i] && tHistory[t[i]] == s[i])
                continue;

            // for being mapped both chars s[i] and t[i] should be unmapped
            // or mapped to each other for isomorphic case
            if ((sHistory[s[i]] == 0 && tHistory[t[i]] != 0) ||
                     (sHistory[s[i]] != 0 && tHistory[t[i]] == 0) ||
                     (sHistory[s[i]] != 0 && 
                        (sHistory[s[i]] != t[i] || tHistory[t[i]] != s[i]))                     
                     )
                return false;

            // creating a one-one mapping for both strings
            sHistory[s[i]] = t[i];
            tHistory[t[i]] = s[i];
        }

        return true;
    }
};