/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* rev(Node* head) {
        Node *p = NULL, *c = head;

        while (c) {
            Node* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }

        return p;
    }

    Node *compute(Node *head) {
        head = rev(head);

        int mx = head->data;
        Node* cur = head;

        while (cur && cur->next) {
            if (cur->next->data < mx) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
                mx = cur->data;
            }
        }

        return rev(head);
    }
};
