//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. 
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int *length=new int[s.size()];
        memset(length,0,s.size()*sizeof(int));
        length[0]=1;
        for(int i=1;i<s.size();i++){
            length[i]=length[i-1]+1;
            for(int j=i-1;j>i-1-length[i-1];j--){
                if(s[j]==s[i]){
                    length[i] = i-j;
                    break;
                }
            }
        }
        int longest=0;
        for(int i=0;i<s.size();i++){
            if(length[i]>longest)
                longest=length[i];
        }
        delete []length;
        return longest;
    }
};