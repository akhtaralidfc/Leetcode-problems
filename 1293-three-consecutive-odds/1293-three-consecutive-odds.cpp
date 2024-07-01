class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(cnt==3) break;
            if(arr[i]%2==1) cnt++; 
            else cnt=0;
            
        }
        return cnt==3;
    }
};