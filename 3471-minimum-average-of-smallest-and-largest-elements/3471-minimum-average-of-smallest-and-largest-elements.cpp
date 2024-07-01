class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        int freq[51]={0},xMin=50,xMax=1;
        double sum=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            xMin=min(xMin,nums[i]);
            xMax=max(xMax,nums[i]);
        }
        double minAv=50;
        for(int i=xMin, j=xMax; n>0; n-=2){
            while (i<j && freq[i]==0) i++;
            while (i<j && freq[j]==0) j--;
            if (i>j) break;
            minAv=min({minAv, double(i+j)/2 });
            if (--freq[i]==0) i++;
            if (--freq[j]==0) j--;
        }
        return minAv;
    }
};