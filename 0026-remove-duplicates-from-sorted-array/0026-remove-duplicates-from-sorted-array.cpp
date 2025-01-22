class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        vector<int> ans;
        set<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i])==st.end()){
                // cout<<arr[i]<<" ";
                ans.push_back(arr[i]);
            }
            st.insert(arr[i]);
        }
        int numberOfUniqueElements=st.size();
        for(int i=0;i<numberOfUniqueElements;i++){
            arr[i]=ans[i];
        }
        return numberOfUniqueElements;
    }
};