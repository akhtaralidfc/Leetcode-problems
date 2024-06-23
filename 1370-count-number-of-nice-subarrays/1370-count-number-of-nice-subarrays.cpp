class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,st=0,n=nums.size();
        int ans=0,tem=0,odd=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                odd++;
                if(odd>=k){
                    tem=1;
                    while(nums[st]%2==0){
                        tem++;
                        st++;
                    }
                    st++;
                    // cout<<st<<" ";
                    ans+=tem;
                }
            }else{
                ans+=tem;
            }
        }
        return ans;
    }
};