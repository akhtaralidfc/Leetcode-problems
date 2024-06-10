class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt=0;
        vector<int> exp(heights.begin(),heights.end());
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=exp[i]) cnt++;
        }
        return cnt;
    }
};