class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int mintime=1e9;
        int maxtime=-1e9;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            mintime=min(mintime,intervals[i][0]);
            maxtime=max(maxtime,intervals[i][1]);
        }
        vector<int> v(maxtime+2,0);
        for(int i=0;i<n;i++){
            v[intervals[i][0]]++;
            v[intervals[i][1]+1]--;
        }
        int ans=0,prefixsum=0;
        for(int i=mintime;i<=maxtime;i++){
            prefixsum+=v[i];
            ans=max(ans,prefixsum);
        }
        return ans;
    }
};