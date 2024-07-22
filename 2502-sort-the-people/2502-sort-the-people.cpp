class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<>> m;
        int n=names.size();
        for(int i=0;i<n;i++){
            m[heights[i]]=names[i];
        }
        vector<string> ans;
        for(auto it: m) ans.push_back(it.second);
        return ans;
    }
};