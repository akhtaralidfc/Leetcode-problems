class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int> m;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int cnt=0;
            for(int j=i;j<s.length();j++){
                if(ch==s[j]){
                    cnt++;
                    m[{ch,cnt}]++;
                }else break;
            }
        }
        int ans=0;
        for(auto it: m){
            char str=it.first.first;
            int len=it.first.second;
            if(it.second>=3 && len>ans) ans=len;
        }
        if(ans==0) return -1;
        return ans;
    }
};