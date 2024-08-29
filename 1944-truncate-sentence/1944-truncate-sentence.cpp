class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt=0;
        string res;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') cnt++;
            if(cnt==k) break;
            res+=s[i];
        }
        // res.pop_back();
        return res;
    }
};