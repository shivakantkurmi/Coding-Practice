/* Definition for Node
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
    int leafLevel = -1;

    bool solve(Node* root, int level) {
        if (!root) return true;

        // Leaf node
        if (!root->left && !root->right) {
            if (leafLevel == -1)
                leafLevel = level;

            return leafLevel == level;
        }

        return solve(root->left, level + 1) &&
               solve(root->right, level + 1);
    }

public:
    bool check(Node* root) {
        //can also use level order traversal 
        return solve(root, 0);
    }
};
