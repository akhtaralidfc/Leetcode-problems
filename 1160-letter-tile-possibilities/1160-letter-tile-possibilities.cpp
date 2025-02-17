class Solution {
public:
    void solver(string tiles, int &result, int begin) {
        result++;
        for(int i=begin;i<tiles.size();i++) {
            if(i!=begin && tiles[i]==tiles[begin]) continue;
            swap(tiles[i],tiles[begin]);
            solver(tiles,result,begin+1);
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int result=-1;
        solver(tiles,result,0);
        return result;
    }
};