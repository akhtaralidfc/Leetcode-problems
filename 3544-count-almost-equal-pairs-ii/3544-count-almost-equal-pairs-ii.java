class Solution {
    // private boolean almostEqual(int a, int b) {
    //     int found = 0;
    //     // first 4 different digits for a and b
    //     int[] ad = new int[4];
    //     int[] bd = new int[4];
    //     while (a > 0 || b > 0) {
    //         if (a%10 != b%10) {
    //             ad[found] = a%10;
    //             bd[found] = b%10;
    //             found++;
    //         }
    //         a /= 10;
    //         b /= 10;
    //         if (found == 4) {
    //             break;
    //         } 
    //     }
        // System.out.print(found+"--");
        // for(int i=0;i<4;i++){
        //     System.out.print(ad[i]);
        //     System.out.print(" ");
        // }
        // System.out.print(":");

        // for(int i=0;i<4;i++){
        //     System.out.print(bd[i]);
        //     System.out.print(" ");
        // }
        // System.out.println();
    //     if (found <= 1) {
    //         return found == 0;
    //     }
    //     if (found == 2 || found == 3) {
    //         Arrays.sort(ad);
    //         Arrays.sort(bd);
    //         return a == b && Arrays.equals(ad, bd);
    //     }
    //     // found == 4
    //     // need to get a matching pair first with the same indices,
    //     // then all digits should match in any order
    //     for (int i = 0; i < 4-1; i++) {
    //         for (int j = i+1; j < 4; j++) {
    //             if (ad[i] == bd[j] && ad[j] == bd[i]) {
    //                 Arrays.sort(ad);
    //                 Arrays.sort(bd);
    //                 // a == b -> check if the rest digits are equal, found 5+ case
    //                 System.out.print(a);
    //                 System.out.print(" "+b);
    //                 System.out.println();
    //                 return a == b && Arrays.equals(ad, bd);
    //             }
    //         }
    //     }
    //     return false;
    // }
    public boolean solve(int a,int b){
        int diff=0;
        int[] adiff=new int[4];
        int[] bdiff=new int[4];
        while(a>0 || b>0){
            if(a%10 != b%10){
                adiff[diff]=a%10;
                bdiff[diff]=b%10;
                diff++;
            }
            
            a/=10;
            b/=10;
            if(diff==4){
                break;
            }
        }
        if(diff<=1){
            return diff==0;
        }
        else if(diff<=3){
            Arrays.sort(adiff);
            Arrays.sort(bdiff);
            return a==b && Arrays.equals(adiff,bdiff);
        }
        else{
            for (int i = 0; i < 3; i++) {
                for (int j = i+1; j < 4; j++) {
                    if (adiff[i] == bdiff[j] && adiff[j] == bdiff[i]) {
                        Arrays.sort(adiff);
                        Arrays.sort(bdiff);
                        return a == b && Arrays.equals(adiff, bdiff);
                    }
                }
            }
        }
        // System.out.println("Heyyyyyyyyyyyy");
        return false;
    }
    public int countPairs(int[] nums) {
        int n=nums.length;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res+=solve(nums[i],nums[j])?1:0;
            }
        }
        return res;
    }
}