
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
          if(head == NULL || head->next == NULL)
    {
        return head;
    }

  ListNode* Prev = NULL;
   ListNode* Curr = head;
  ListNode* forward = NULL;

    while(Curr != NULL)
    {
        // Step 1: Next node ka address save karo
        forward = Curr->next;

        // Step 2: Current node ka link reverse karo
        Curr->next = Prev;

        // Step 3: Prev ko current node par le aao
        Prev = Curr;

        // Step 4: Next node par move karo
        Curr = forward;
    }

    // Loop ke end mein Prev reversed list ka head hota hai
    return Prev;
    }
};