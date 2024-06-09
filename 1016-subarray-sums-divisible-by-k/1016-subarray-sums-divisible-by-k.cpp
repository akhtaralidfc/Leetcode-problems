class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum%k==0) cnt++;
            int rem=sum%k;
            if(rem<0) rem=rem+k;
            if(m.find(rem)!=m.end()) cnt+=m[rem];
            m[rem]++;
        }
        return cnt;
    //    int ans=0,sum=0;
    //    map<int,int> m;
    //    int rem=0;
    //    for(int i=0;i<nums.size();i++){
    //        sum+=nums[i];
    //        if(sum%k==0){
    //             ans++;
    //             // cout<<"ans1:"<<ans<<endl;
    //        } 
    //        rem=sum%k;
    //     //    cout<<rem<<endl;
    //        if(rem<0) rem=rem+k; 
    //        if(m.find(rem)!=m.end()){
    //            ans=ans+m[rem];
    //         //    cout<<"ans2:"<<ans<<endl;
    //        }
    //        m[rem]++;
    //    }
    //     return ans;
    }
};