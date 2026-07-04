/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int inOrderSuccessor(Node *root, Node *k) {

        // Case 1
        if (k->right) {
            Node* curr = k->right;
            while (curr->left)
                curr = curr->left;
            return curr->data;
        }

        // Case 2
        Node* succ = nullptr;
        Node* curr = root;

        while (curr) {
            if (k->data < curr->data) {
                succ = curr;
                curr = curr->left;
            }
            else if (k->data > curr->data) {
                curr = curr->right;
            }
            else {
                break;
            }
        }

        return succ ? succ->data : -1;
    }
};
