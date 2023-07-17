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
    ListNode* reverse(ListNode* h){
        ListNode *prev=NULL,*cur=h,*nxt=NULL;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1=l1,*ptr2=l2,*dummy = new ListNode(0),*ptr3 = dummy;
        ptr1 = reverse(ptr1);
        ptr2 = reverse(ptr2);
        
        int div =0;
        while(ptr1 || ptr2 || div){
            
            int no1,no2,sum=0;
            
            no1 = ptr1==nullptr? 0: ptr1->val;
            no2 = ptr2==nullptr? 0: ptr2->val;
            sum = no1+no2+div;
            div = sum/10;
            
            ListNode* temp = new ListNode(sum%10);
            ptr3->next =temp;
            ptr3 = ptr3->next;
            ptr1 = ptr1==nullptr? 0: ptr1->next;
            ptr2 = ptr2==nullptr? 0: ptr2->next;
        }
        
        return reverse(dummy->next);
    }
};
