//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") ¡ú false
//isMatch("aa","aa") ¡ú true
//isMatch("aaa","aa") ¡ú false
//isMatch("aa", "a*") ¡ú true
//isMatch("aa", ".*") ¡ú true
//isMatch("ab", ".*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú true

class Solution {
public:
    bool match(const char *s, const char *p) {
        if(p[0]==0){
            if(s[0]==0) return true;
            else return false;
        } 
        if(p[1]=='*'){
			int i=-1;
			do{
				i++;
				if(match(&s[i],&p[2])){
					return true;
				}
			}while(s[i]!=0 && (s[i]==p[0] || p[0]=='.'));	
			return false;
		}
        if(p[1]!='*'){
			if(s[0]==0) return false;
            if(s[0]==p[0] || p[0]=='.'){
				return match(&s[1],&p[1]);
            }else return false;
        }
	}
	bool isMatch(string s, string p){
	    const char *_s=s.c_str();
	    const char *_p=p.c_str();
	    return match(_s,_p);
	}
};