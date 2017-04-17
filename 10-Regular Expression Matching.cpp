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
    bool isMatch(string s, string p) {
        if(s.size()==0 && p.size()==0) return true;
        if(s.size()==0) {
            if(p.size()>2 && p[1]=='*')
                return isMatch(s,p.substr(2));
            else if(p.size()==2 && p[1]=='*')
				return true;
            else return false;
        }
        if(p.size()==0) return false;
		if(p.size()==1){
			if(s[0]==p[0] || p[0]=='.') return isMatch(s.substr(1),p.substr(1));
			else return false;
		} 
        if(p.size()>1 && p[1]!='*'){
            if(p[0]=='.' || s[0]==p[0]){
				return isMatch(s.substr(1),p.substr(1));
            }else return false;
        }
		if(p.size()>1 && p[1]=='*'){
			int i=-1;
			do{
				i++;
				if(isMatch(s.substr(i),p.substr(2))){
					return true;
				}
			}while(i<s.size() && (s[i]==p[0] || p[0]=='.'));	
			return false;
		}
	}
};