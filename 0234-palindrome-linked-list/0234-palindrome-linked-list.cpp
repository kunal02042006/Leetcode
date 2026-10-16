
class Solution {
     private:
  ListNode*getMid(ListNode* head){
    ListNode* slow = head;
   ListNode* fast = head->next;

        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;  } 
            return slow; }

    ListNode*reverse(ListNode*head){
       ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
             if(head == NULL || head->next == NULL){
            return true;
        }
        // step1 find middle
       ListNode* Middle = getMid(head);

        // step2 reverse list after middle
        ListNode*temp = Middle->next;
         Middle->next = reverse(temp);

         //step3 compare krna hai both halves
        ListNode*head1 = head;
        ListNode*head2 = Middle->next;

         while(head2 != NULL){
             if(head1->val != head2->val){
                 return false;
             }

             head1 = head1->next;
             head2 = head2->next;
         }

         //step4 step2 repeat karo
          temp = Middle->next;
         Middle->next = reverse(temp);

         return true;
    }
        

};