class Solution {
public:
    int passThePillow(int n, int time) {
        int round=time/(n-1);
        //if it is moving from left to right
        if(round%2==0) return 1+(time%(n-1));
        //if it is moving from right to left
        else return n-(time%(n-1));
    }
};