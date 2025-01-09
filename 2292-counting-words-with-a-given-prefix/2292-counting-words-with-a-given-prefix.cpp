class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int baby=0;
        int len=pref.size();
        for(auto it:words){
            if(it.substr(0,len)==pref) baby++;
        }
        return baby;
    }
};