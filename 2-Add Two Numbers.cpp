//You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *result = new ListNode(0);
        ListNode *base=result;
        int pro=0;
        while(1){
            int x1=0,x2=0;
            if(temp1 !=NULL){
                x1 = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 !=NULL){
                x2 = temp2->val;
                temp2 = temp2->next;
            }                                     
            result->val = x1 + x2 +pro; 
            pro = result->val/10;
            if(result->val>9){
                result->val = result->val-10;
            }
            if(temp1 != NULL || temp2 != NULL ){
                result->next = new ListNode(0);
                result= result->next;
            }else{
                if(pro)
                    result->next = new ListNode(pro);
                break;
            }
        }
        return base;
        
    }
};