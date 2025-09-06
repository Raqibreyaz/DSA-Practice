class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        cout<<s<<endl;

        int newLength = removeExtraSpace(s);

        cout<<"\""<<s<<"\""<<endl;

        // removing all the unnecessary characters
        s.erase(newLength);

        while(s.back() == ' ')
            s.pop_back();

        cout<<"\""<<s<<"\""<<endl;

        reverseWordByWord(s);

        cout<<"\""<<s<<"\""<<endl;

        return s;
    }

private:
    
    // returns length of modified string
    int removeExtraSpace(string& str){
        int i,j;
        for(i = 0, j = 0; j < str.size(); j++){

            if(i != j)
                swap(str[i],str[j]);

            if(i == 0 && str[i] == ' ' || str[i] == ' ' && str[i-1] == ' '){
                continue;
            }

            i++;
        }
        return i;
    }
    
    void reverseWordByWord(string& str){
        for(int i = 0, j = 0; j < str.size();j++){

            // find word's end
            while(j < str.size() && str[j] != ' ') j++;

            // reversing the word
            reverse(str.begin() + i, str.begin() + j);

            i = j;

            // skipping the space and going to next word
            while(i < str.size() && str[i] == ' ') i++;
            j = i;
        }
    }
};