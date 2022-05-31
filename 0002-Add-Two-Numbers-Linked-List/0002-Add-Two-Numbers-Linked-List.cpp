/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* res = new ListNode();
        ListNode* ans = res;
        int carry = 0;
        while(ptr1!=NULL || ptr2!=NULL)
        {
            int sum = (ptr1!=NULL ? ptr1->val:0) 
                      + (ptr2!=NULL ? ptr2->val:0) 
                      + carry;
            carry = 0;
            if(sum>9){
                sum = sum-10;
                carry = 1;
            }
            ans->next = new ListNode(sum);
            if(ptr1!=NULL)
                ptr1 = ptr1->next;
            if(ptr2!=NULL)
                ptr2 = ptr2->next;
            ans = ans->next;
        }
        if(carry!=0)
        {
            int sum = carry;
            carry=0;
            ans->next = new ListNode(sum);
            ans = ans->next;
        }
        return res->next;
    }
};
