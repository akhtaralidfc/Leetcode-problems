class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal=arrays[0][0];
        int maxVal=arrays[0].back();
        int maxD=0;
        for(int i=1;i<arrays.size();i++){
            int curMin=arrays[i][0];
            int curMax=arrays[i].back();
            maxD=max(maxD,abs(curMax-minVal));
            maxD=max(maxD,abs(maxVal-curMin));
            minVal=min(minVal,curMin);
            maxVal=max(maxVal,curMax);
        }
        return maxD;
    }
};