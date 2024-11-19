class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {   
            st.push(s[i]);
            if(s[i]==']')
            {
                st.pop();
                string temp="";
                while(!st.empty() && st.top()!='[')
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                string d="";
                while(!st.empty() && isdigit(st.top()))
                {
                    d=st.top()+d;
                    st.pop();
                }
                int num=stoi(d);
                string result="";
                while(num--)
                {
                    result+=temp;
                }
                // ans+=result;
                for(auto c:result)
                {
                    st.push(c);
                }
            }
        }
        // cout<<ans<<endl;
        // return ans;
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};