#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for Node
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

class Solution{
    public:
        Node* copyRandomList(Node* head){
            if(head == NULL){
                return NULL;
            }

            unordered_map<Node*, Node*> m;

            Node* newHead = new Node(head->val);
            Node* oldTemp = head->next;
            Node* newTemp = newHead;
            m[head] = newHead;

            while(oldTemp != NULL){
                Node* copyNode = new Node(oldTemp->val);
                m[oldTemp] = copyNode;
                newTemp->next = copyNode;

                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }

            oldTemp = head;
            newTemp = newHead;
            while(oldTemp != NULL){
                newTemp->random = m[oldTemp->random];
                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }

            return newHead;
        }
};

// Helper function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << "Value: " << head->val;

        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;
        head = head->next;
    }
}

int main() {
    // Creating a sample list:
    // 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    // Setting random pointers
    n1->random = n3; // 1 -> 3
    n2->random = n1; // 2 -> 1
    n3->random = NULL;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}