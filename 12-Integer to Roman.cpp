//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
//Subscribe to see which companies asked this question.

class Solution {
public:
    string intToRoman(int num) {
        string out;
        while(num>0){
            if(num>=900){
                if(num>=1000)    {out += "M";num-=1000;}
                else {out += "CM";num-=900;}
            }else if(num >=400){
                if(num>=500) {out += "D";num-=500;}
                else {out += "CD";num-=400;}
            }else if(num>=90){
                if(num>=100) {out += "C";num-=100;}
                //else if(num>=99) {out += "IC";num-=99;}
                else {out += "XC";num-=90;} 
            }else if(num>=40){
                if(num>=50) {out += "L";num-=50;}
                else {out += "XL";num-=40;} 
            }else if(num>=9){
                if(num>=10) {out += "X";num -= 10;}
                else {out += "IX";num-=9;} 
            }else if(num>=4){
                if(num>=5) {out += "V";num-=5;}
                else {out += "IV";num-=4;} 
            }else{
                out += "I";
                num-=1;
            }
        }
    return out;
    }
};