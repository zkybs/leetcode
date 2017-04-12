//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        int size=s.size();
        string out;
        if(numRows==1) return s;
        for(int i=0;i<numRows;i++){
            int lasti=i;
            out += s[lasti];
            int colums=1;
            int steps=1;
            while(true){
                if(colums%2)
                    steps=2*(numRows-i-1);
                else
                    steps=2*i;
                lasti += steps;
                if(lasti>=size) break;
                if(steps)
                    out += s[lasti];
                colums++;

            }
        }
        return out;
    }
};