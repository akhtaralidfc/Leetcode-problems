class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int ans=0;
        for(auto it: s){
           if(m.find(it)!=m.end()){
            ans+=2;
            m.erase(it);
           }else{
            m[it]++;
           }
        }
        if(m.size()>0) return ans+1;
        else return ans;
    }
};