class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        // vector<int> ans;
        int ind=arr[0].size()-1;
        int ans=0,cnt=0,res=0;
        for(int i=0;i<arr.size();i++){
            sort(arr[i].begin(),arr[i].end());
            if(ind>=0 && arr[i][ind]==1){
                while(ind>=0 && arr[i][ind]==1){
                    cnt++;
                    if(cnt>ans){
                        ans=cnt;
                        res=i;
                    }
                    ind--;
                }
            }
            else if(ind<0) break;
        }
        return {res,ans};
    }
};