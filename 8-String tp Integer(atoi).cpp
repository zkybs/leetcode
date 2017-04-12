//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, 
//please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
//You are responsible to gather all the input requirements up front.

class Solution {
public:
    int myAtoi(string str) {
        long long a=0;
        int posit=0;
        int size=str.size();
        int special=0;
        for(int i=0;i<size;i++){
            if(str[i]<='9' && str[i]>='0'){
                a = a*10+str[i]-'0';
                if(a>2147483648) break;
                if(i+1>=str.size()) break;
                if(str[i+1]>'9' || str[i+1]<'0') break;
                continue;
            }
            if((str[i]=='+' || str[i]=='-') && special)
                return 0;
            if((str[i]=='+' ||str[i]=='-') && !special){
                if(i+1>=str.size()) return 0;
                if(str[i+1]>'9' || str[i+1]<'0') return 0;
                posit=(str[i]=='-');
                special=1;
                continue;
            }
            if(str[i]!=' ' && str[i]!='+' && str[i]!='-')
                return 0;
        }
        a=posit==1?-a:a;
        if(a>2147483647) return 2147483647;
        if(a<-2147483648) return -2147483648;
        return a; 
    }
};