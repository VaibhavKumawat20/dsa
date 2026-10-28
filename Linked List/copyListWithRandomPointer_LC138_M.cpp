#include <iostream>
#include <unordered_map>
using namespace std;

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {
            if (oldTemp->random != NULL) {
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << "Value: " << temp->val;

        if (temp->random != NULL) {
            cout << ", Random: " << temp->random->val;
        } else {
            cout << ", Random: NULL";
        }

        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Create the original list: 7 -> 13 -> 11
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);

    // Set random pointers
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next;

    Solution obj;

    Node* copiedHead = obj.copyRandomList(head);

    cout << "Original List:" << endl;
    printList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedHead);

    return 0;
}
