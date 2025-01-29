class Solution {
    boolean check(String str){
        int n=str.length();
        if(n==1) return true;
        if(n>=2 && str.charAt(0)=='0') return false;
        return Integer.parseInt(str)<=255;
    }
    public List<String> restoreIpAddresses(String s) {
        List<String> res=new ArrayList<>();
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i+j+k<s.length() && i+j+k+3>=s.length()){
                        String a=s.substring(0,i);
                        String b=s.substring(i,i+j);
                        String c=s.substring(i+j,i+j+k);
                        String d=s.substring(i+j+k);
                        if(check(a) && check(b) && check(c) && check(d)){
                            String temp=a+"."+b+"."+c+"."+d;
                            res.add(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
}