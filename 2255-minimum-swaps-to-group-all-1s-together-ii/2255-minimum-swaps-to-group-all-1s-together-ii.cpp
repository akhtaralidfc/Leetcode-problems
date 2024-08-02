class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int onecnt=0;
        for(auto it: nums) if(it==1) onecnt++;
        int i=0,j=0,n=nums.size();
        int ans=1e9;
        int cnt=0;
        while(j<n+onecnt){
            cnt+=nums[j%n];
            if(j-i+1>onecnt){
                cnt-=nums[i%n];
                i++;
            }
            if(j-i+1 == onecnt){
                ans=min(ans,onecnt-cnt);
            }
            j++;
        }
        return ans;
    }
};
