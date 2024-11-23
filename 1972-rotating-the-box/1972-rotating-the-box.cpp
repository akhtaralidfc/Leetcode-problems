class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        int i=0;
        while(i<m){
            int j=n-1,a=j,b=m-i-1;
            while(j>=0){
                if(box[i][j]=='#'){
                    ans[a][b]='#';
                    a--;
                }
                else if(box[i][j]=='*'){
                    ans[j][b]='*';
                    a=j-1;
                }
                j--;
            }
            i++;
        }
        return ans;
    }
};