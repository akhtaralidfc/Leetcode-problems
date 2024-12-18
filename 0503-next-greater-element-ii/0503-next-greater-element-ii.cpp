class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0;i<2*n;i++)
        {
            while(!st.empty() && nums[st.top()%n]<nums[i%n])
            {
                ans[st.top()%n]=nums[i%n];
                // cout<<i%n<<" "<<st.top()<<" ";
                st.pop();
            }
            //  if(st.empty()) cout<<"y ";
            st.push(i%n);
            // cout<<"i:"<<i%n<<endl;
           
        }
        return ans;
    }
};