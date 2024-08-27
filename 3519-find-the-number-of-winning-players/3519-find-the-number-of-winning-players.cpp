class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>> m;
        unordered_map<int, int> m2;
        unordered_set<int> st;
        for(int i = 0; i < pick.size(); i++) {
            m[pick[i][0]].push_back(pick[i][1]);
        }
        for(auto it : m) {
            int maxi = 0;
            vector<int> t = it.second;
            for(auto it2 : t) {
                m2[it2]++;
            }
            for(auto it3 : m2) {
                maxi = max(maxi, it3.second);
            }
            if(it.first < maxi) {
                st.insert(it.first);
            }
            m2.clear();
        }

        return st.size();
    }
};