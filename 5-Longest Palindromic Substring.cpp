//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//Example:
//
//Input: "cbbd"
//
//Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        int len1[1000];
        int len2[1000];
        int max1=0,maxIndex1;
        int max2=0,maxIndex2;
        memset(len1,0,sizeof(len1));
        memset(len2,0,sizeof(len2));
        for(int i=0;i<size;i++){
            len1[i] += 1;
            for(int j=1;j<size;j++){
                if((i-j)<0 || (i+j)>=size || s[i-j]!=s[i+j])
                    break;
                len1[i] += 2;
            }
            if(len1[i]>max1){
                max1=len1[i];
                maxIndex1=i;
            }
        }
        for(int i=0;i<size;i++){
            for(int j=1;j<size;j++){
                if((i-j+1)<0 || (i+j)>=size || s[i-j+1]!=s[i+j])
                    break;
                len2[i] += 2;
            }
            if(len2[i]>max2){
                max2=len2[i];
                maxIndex2=i;
            }
        }
        if(max1>max2)
            return s.substr(maxIndex1-len1[maxIndex1]/2,len1[maxIndex1]);
        else
            return s.substr(maxIndex2-len2[maxIndex2]/2+1,len2[maxIndex2]);
    }
};