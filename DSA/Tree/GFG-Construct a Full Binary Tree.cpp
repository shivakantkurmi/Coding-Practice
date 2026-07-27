/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    int preIndex;
    unordered_map<int, int> pos;

    Node* build(vector<int>& pre, vector<int>& mirror, int l, int r) {

        if (preIndex >= pre.size() || l > r)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == r || preIndex >= pre.size())
            return root;

        int idx = pos[pre[preIndex]];

        if (idx <= r) {
            root->left = build(pre, mirror, idx, r);
            root->right = build(pre, mirror, l + 1, idx - 1);
        }

        return root;
    }

public:
    Node* constructBinaryTree(vector<int>& pre,
                              vector<int>& preMirror) {

        preIndex = 0;

        for (int i = 0; i < preMirror.size(); i++)
            pos[preMirror[i]] = i;

        return build(pre, preMirror, 0, preMirror.size() - 1);
    }
};
