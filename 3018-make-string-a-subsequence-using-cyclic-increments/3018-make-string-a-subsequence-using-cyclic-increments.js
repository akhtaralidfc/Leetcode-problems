/**
 * @param {string} str1
 * @param {string} str2
 * @return {boolean}
 */
var canMakeSubsequence = function(str1, str2) {
    let cnt=str2.length;
    let j=0;
    for(let i=0;i<str1.length && j<str2.length;i++){
        if(str1[i]===str2[j]) j++;
        else{
            let nextChar = str1[i]==='z'?'a':String.fromCharCode(str1.charCodeAt(i)+1);
            if(nextChar===str2[j]){
                j++;
            }
        }
    }
    return j>=cnt;
};