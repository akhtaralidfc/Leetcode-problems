class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        for(int i=1;i<n-1;i++){
            int leftsmall=0,leftlarge=0;
            int rightsmall=0,rightlarge=0;
            //left part
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    leftsmall++;
                }
                if(arr[j]>arr[i]){
                    leftlarge++;
                }
            }
            //right part
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    rightsmall++;
                }
                if(arr[j]>arr[i]){
                    rightlarge++;
                }
            }
            // leftsmall*rightlarge is cnt of arrays of ascending array and leftlarge*rightsmall is the cnt of arrays in descending order
            res+=(leftsmall*rightlarge) + (leftlarge*rightsmall);
        }
        return res;
    }
};