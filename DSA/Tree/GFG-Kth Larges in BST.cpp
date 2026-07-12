/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    int countNode(Node* root) {
        if (!root) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }

    int findKthSmallest(Node* root, int k, int &cnt) {
        if (!root) return -1;

        int left = findKthSmallest(root->left, k, cnt);
        if (left != -1) return left;

        cnt++;
        if (cnt == k) return root->data;

        return findKthSmallest(root->right, k, cnt);
    }

public:
    int kthLargest(Node* root, int k) {
        int n = countNode(root);
        int cnt = 0;
        return findKthSmallest(root, n - k + 1, cnt);
    }
};
