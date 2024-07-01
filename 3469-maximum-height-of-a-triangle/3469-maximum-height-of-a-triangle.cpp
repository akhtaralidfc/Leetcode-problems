class Solution {
public:
    int solve(int red,int blue){
        int numofballsreq=1,h=0;
        while(1){
            if(h%2){
                if(red>=numofballsreq) red-=numofballsreq;
                else  break;
            }
            else{
                if(blue>=numofballsreq) blue-=numofballsreq;
                else break;
            }
            numofballsreq++;
            h++;
        }
        return h;

    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};