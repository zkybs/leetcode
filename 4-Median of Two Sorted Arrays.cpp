//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//   
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a=nums1;
        vector<int> b=nums2;
        if(nums1.size()>nums2.size()){
            a=nums2;
            b=nums1;
        }
        int leng1=a.size();
        int leng2=b.size();
        if(leng1<1){
            if(!(leng2%2)) return float(b[(leng2-1)/2]+b[leng2/2])/2.0f;
            if(leng2%2) return float(b[leng2/2]);
        }
        if(leng2<1) return 0;
        int begin=0,tail=a.size(),halfl=(leng1+leng2+1)/2;
        while(begin<=tail){
            int i=(begin+tail)/2;
            int j=halfl-i;
            if((i<leng1) && b[j-1]>a[i]){
                begin=i+1;
            }else if(i>0 && a[i-1]>b[j]){
                tail=i-1;
            }else{
                int maxleft=0,minright=0;
                if(i==0) maxleft=b[j-1];
                else if(j==0) maxleft=a[i-1];
                else maxleft=max(a[i-1],b[j-1]);
                
                if(((leng1+ leng2)%2) ==1)
                    return maxleft;
                
                if(i==leng1) minright=b[j];
                else if(j==leng2) minright=a[i];
                else minright=min(a[i],b[j]);
                
                return (maxleft+minright)/2.0f;
            }
        }
    }
};