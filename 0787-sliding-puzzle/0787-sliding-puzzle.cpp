class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string begin="",end="123450";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++)
                begin.push_back((char)(board[i][j] + '0'));
        }
        vector<vector<int>> moves={{1,3},{0,2,4},{1,5},{0,4},{3,1,5},{4,2}};
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({begin,0});
        vis.insert(begin);
        while(!q.empty()){
            auto [curr,dist]=q.front();
            q.pop();
            if(curr==end) return dist;
            int ind=curr.find("0");
            for(auto it: moves[ind]){
                swap(curr[ind], curr[it]);
                // cout<<curr<<" ";
                if(!vis.count(curr)) {
                    q.push({curr,dist+1});
                    vis.insert(curr);
                }
                swap(curr[ind], curr[it]);
            }
        }
        return -1;
    }
};