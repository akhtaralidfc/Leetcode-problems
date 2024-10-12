class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chaircnt=0,n=times.size();
        int targetarrival=times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<>> q1;
        priority_queue<int,vector<int>,greater<int>> chairq;
        for(int i=0;i<n;i++){
            int curarr=times[i][0];
            int curdep=times[i][1];
            // cout<<curarr<<" "<<curdep<<endl;
            int curchair=0;
            while(!q1.empty() && q1.top().first<=curarr){
                chairq.push(q1.top().second);
                q1.pop();
            }
            if(!chairq.empty()){
                curchair=chairq.top();
                chairq.pop();
            }else{
                curchair=chaircnt;
                chaircnt++;
            }
            q1.push({curdep,curchair});
            if(curarr==targetarrival) return curchair;
        }

        
        // for(auto it: times) cout<<it.first<<" "<<it.second<<endl;
        return 0;
    }
};