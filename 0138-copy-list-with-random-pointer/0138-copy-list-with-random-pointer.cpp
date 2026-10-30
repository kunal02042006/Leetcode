/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
               // STEP 1: CREATE A COPY LIST
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            insertAtTail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // STEP 2: ADD CLONE NODES BETWEEN ORIGINAL NODES

        Node* originalNode = head;
        Node* cloneNode = clonehead;

        while (originalNode != NULL) {
            Node* next = originalNode->next;

            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // STEP 3: COPY RANDOM POINTERS

        temp = head;

        while (temp != NULL) {

            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            else {
                temp->next->random = NULL;
            }

            // Next original node par jaane ke liye 2 baar next
            temp = temp->next->next;
        }

        // STEP 4: RESTORE ORIGINAL LIST AND SEPARATE CLONE

        originalNode = head;
        cloneNode = clonehead;

        while (originalNode != NULL && cloneNode != NULL) {

            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }

        // STEP 5: RETURN CLONED LIST
        return clonehead;
        
    }
};