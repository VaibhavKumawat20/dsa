#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                // flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                // find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                // attach tail with next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Example:
    // 1 - 2 - 3
    //         |
    //         7 - 8

    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->child = n7;
    n7->next = n8;
    n8->prev = n7;

    Solution obj;
    Node* flatHead = obj.flatten(head);

    cout << "Flattened list: ";
    printList(flatHead);

    return 0;
}