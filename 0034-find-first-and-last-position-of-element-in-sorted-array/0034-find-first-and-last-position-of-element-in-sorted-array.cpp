class Solution {
public:
   int lower_bound(vector<int>& arr, int x)
{
  int n=arr.size();
    int low=0, high=n-1, mid;
    
    while(low<high)
    {
        mid=(low+high)/2;
        if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
     
}
int foc(vector<int>& arr, int x){
    int ans=-1;
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low)+(high-low)/2;
        if(arr[mid]==x) ans=mid;
        if(arr[mid]>=x){
            // ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<"foc"<<endl;
    if(ans!=-1) return ans;
    return -1;
}
int loc(vector<int>& arr, int x){
    int ans=-1;
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low)+(high-low)/2;
        if(arr[mid]==x) ans=mid;
        if(arr[mid]<=x){
            // ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<"loc"<<endl;
    if(ans!=-1) return ans;
    return -1;
}
int upper_bound(vector<int>& arr, int x)
{    int n=arr.size();
     int low=0, high=n-1, mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if(arr[mid]<=x)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}
    vector<int> searchRange(vector<int>& arr, int x) {
        int n=arr.size();
        // if(!n) return {-1, -1};
        // auto idx1=lower_bound(arr,  x);
        // auto idx2=upper_bound(arr, x);
        // if(arr[idx1]!=x) return {-1, -1};
        // if(arr[idx2]!=x) idx2--;
        int idx1=foc(arr,x);
        int idx2=loc(arr,x);
        // cout<<idx1<<" "<<idx2<<endl;
        return {idx1, idx2};
    }
};
