/* A binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
    Node* lca(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b)
            return root;

        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);

        if (left && right)
            return root;

        return left ? left : right;
    }

    int distance(Node* root, int x) {
        if (!root)
            return -1;

        if (root->data == x)
            return 0;

        int left = distance(root->left, x);
        if (left != -1)
            return left + 1;

        int right = distance(root->right, x);
        if (right != -1)
            return right + 1;

        return -1;
    }

public:
    int findDist(Node* root, int a, int b) {
        Node* LCA = lca(root, a, b);

        int d1 = distance(LCA, a);
        int d2 = distance(LCA, b);

        return d1 + d2;
    }
};
