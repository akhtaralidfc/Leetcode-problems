class Solution {
public:
    void solve(int prev,string &str,int n,vector<string> &ans){
        if(str.length()==n){
            ans.push_back(str);
            return;
        }
        str.push_back('1');
        solve(1,str,n,ans);
        str.pop_back();
        if(prev==1){
            str.push_back('0');
            solve(0,str,n,ans);
            str.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string a="0",b="1";
        vector<string> res;
        solve(0,a,n,res);
        solve(1,b,n,res);
        return res;
    }
};