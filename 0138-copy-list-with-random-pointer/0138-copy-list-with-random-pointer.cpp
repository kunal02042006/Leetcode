/*
Definition for a Node.
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

        // STEP 1: CREATE A CLONE LIST
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            insertAtTail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // STEP 2: CREATE A MAP
        unordered_map<Node*, Node*> oldToNew;

        Node* originalNode = head;
        Node* cloneNode = clonehead;

        while (originalNode != NULL) {
            oldToNew[originalNode] = cloneNode;

            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // STEP 3: COPY RANDOM POINTERS
        originalNode = head;
        cloneNode = clonehead;

        while (originalNode != NULL) {
            if (originalNode->random != NULL) {
                cloneNode->random = oldToNew[originalNode->random];
            }
            else {
                cloneNode->random = NULL;
            }

            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return clonehead;
    }
};