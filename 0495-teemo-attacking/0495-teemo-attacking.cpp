class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int duration) {
        int ans=0,lultime=0;;
        int n=ts.size();
        lultime=ts[0]+duration-1;
        // if(n>1){
        //     if(ts[1]>lultime) ans+=duration;
        //     else ans+=ts[1]-ts[0];
        // }
        // cout<<ans;
        for(int i=1;i<n;i++){
            if(ts[i]>lultime){
                lultime=ts[i]+duration-1;
                ans+=duration;
            }else{
                ans+=ts[i]-ts[i-1];
                lultime=ts[i]+duration-1;
            }
        }
        ans+=duration;
        return ans;
    }
};