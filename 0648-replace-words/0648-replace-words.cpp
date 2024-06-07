class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        string ans, word;
        bool isFound=0;
        for(auto c: sentence){
            if (c!= ' '){
                word+=c;
                if (!isFound && st.count(word)){
                    ans+=word;
                    isFound=1;
                }
            } 
            else{
                if(!isFound) ans+=word;
                ans+=' ';
                word="";
                isFound=0;
            }
        }
        if(!isFound)
            ans+=word;

        return ans;
    }
};