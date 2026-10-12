
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    // Base case
    if(head == NULL){
        return NULL;
    }

    // Check if k nodes are available
  ListNode* temp = head;
    int nodes = 0;

    while(temp != NULL && nodes < k){
        temp = temp->next;
        nodes++;
    }

    // Agar k se kam nodes hain, toh unchanged return karo
    if(nodes < k){
        return head;
    }

    // STEP 1: Reverse first k nodes
    ListNode* prev = NULL;
    ListNode* curr = head;
   ListNode* forward = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // STEP 2: Remaining list ko recursively reverse karo
    if(forward != NULL){
        head->next =reverseKGroup(forward, k);
    }

    return prev;
}

        

};