class Solution {
public:
    int way[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        res.push_back({r0,c0});
        int direction=0,end_cnt=1;
        for(int i=0;end_cnt<R*C;i++){
            int cnt = i/2+1;
            while(cnt--){
                r0 += way[direction][0];
                c0 += way[direction][1];
                if(r0>=0 && r0<R && c0<C && c0>=0){
                    res.push_back({r0,c0});
                    end_cnt++;
                }
            }
            direction=(direction+1)%4;
        }
        return res;
    }
};