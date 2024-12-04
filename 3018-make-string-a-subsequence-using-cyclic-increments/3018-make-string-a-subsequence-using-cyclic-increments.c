bool canMakeSubsequence(char* str1, char* str2) {
    int cnt=strlen(str2);
    int j=0;
    for(int i=0;str1[i]!='\0' && str2[j]!='\0';i++){
        if(str1[i]==str2[j]){
            j++;
        }else{
            char tem=str1[i];
            if(tem=='z') tem='a';
            else tem++;
            if(tem==str2[j]) j++;
        }
    }
    if(j>=cnt) return true;
    return false;
}