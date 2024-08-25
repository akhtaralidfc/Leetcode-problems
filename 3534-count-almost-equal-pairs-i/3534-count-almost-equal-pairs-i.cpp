class Solution {
public:
    bool solve2(int x, int y){
        string s1=to_string(x),s2=to_string(y);
        int diff=0,n=s1.length(),m=s2.length();
        int maxLen = max(n, m);
        while(n!=maxLen){
            s1="0"+s1;
            n++;
        }
        while(m!=maxLen){
            s2="0"+s2;
            m++;
        }
        // cout<<s1<<" "<<s2<<endl;
        for(int i = 0; i < n; i++){
            diff += (s1[i] != s2[i]);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return diff <= 2 && s1 == s2;
    }
    int countPairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt+=solve2(nums[i],nums[j]);
            }
        }
        return cnt;
    }
};