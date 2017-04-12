//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//click to show spoilers.
//
//Note:
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        uint posit=x>0?x:-x;
        long out=0;
        while(posit>0){
            out =10*out +posit%10;
            posit = posit/10;
        }
        return out>0x7FFFFFFF?0:(x>0?int(out):int(-out));
    }
};