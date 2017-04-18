//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
//n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//Find two lines, which together with x-axis forms a container, 
//such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxStart=0,maxEnd=height.size()-1;
        int max=min(height[maxStart],height[maxEnd])*maxEnd;
        for(int i=0;i<maxEnd;i++){
            int tempM=min(height[i],height[maxEnd])*(maxEnd-i);
            if(tempM>max) {
                max=tempM;
            }
            maxStart=i;
            if(height[i]>height[maxEnd]){
                for(int j=maxEnd-1;j>i;j--){
                    int tempM=min(height[i],height[j])*(j-i);
                    if(tempM>max){
                        max=tempM;
                    }  
                    maxEnd=j;
                    if(height[maxEnd]>height[i])
                        break;
                }
            }
        }
        return max;
    }
};