class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        int n=pos.size();
        vector<vector<int>> v;
        int f=0,f1=0;
        for(int i=0;i<n;i++){
            if(dir[i]=='L') f1=1;
            v.push_back({pos[i],health[i],dir[i],i});
        }
        sort(v.begin(),v.end());
        // for(auto it: v) {
        //     cout<<it[0]<<" "<<it[1]<<" "<<static_cast<char>(it[2]);
        //     cout<<endl;
        // }
        stack<vector<int>> st;
        for(int i=0;i<n;i++){
            if (static_cast<char>(v[i][2])=='R' || st.empty() || static_cast<char>(st.top()[2])=='L') {
                st.push({v[i][0],v[i][1],v[i][2],v[i][3]});
                continue;
            }
            if(static_cast<char>(v[i][2])=='L'){
                bool add=true;
                while(!(st.empty()) && static_cast<char>(st.top()[2])=='R'&& add){
                    if(v[i][1]>st.top()[1] ){
                        st.pop();
                        v[i][1]-=1;
                        f=1;
                    }else if(v[i][1]<st.top()[1]){
                        st.top()[1]-=1;
                        add=false;
                        f=1;
                        
                    }
                    else{
                        st.pop();
                        add=false;
                    }
                }
                if(add){
                    st.push({v[i][0],v[i][1],v[i][2],v[i][3]});
                }
            }
            
        }
        vector<vector<int>> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[3] < b[3];
        });
        vector<int> res;
        for (auto it: arr) {
            res.push_back(it[1]);
        }
        // while(!st.empty()){
        //     res.push_back(st.top()[1]);
        //     st.pop();
        // }
        //  reverse(res.begin(),res.end());
        // if(dir.find('L')==string::npos) reverse(res.begin(),res.end());
        return res;
    }
};