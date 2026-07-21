/* Structure of Binary Tree Node
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
    Node* t = nullptr;

    void createParent(unordered_map<Node*, Node*>& parent, Node* root, int target) {
        if (!root) return;

        if (root->data == target)
            t = root;

        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;

        createParent(parent, root->left, target);
        createParent(parent, root->right, target);
    }

public:
    vector<int> kDistanceNodes(Node* root, int target, int k) {

        unordered_map<Node*, bool> vis;
        unordered_map<Node*, Node*> parent;
        vector<int> ans;

        createParent(parent, root, target);

        queue<Node*> q;
        q.push(t);
        vis[t] = true;

        int level = 0;

        while (!q.empty()) {

            int s = q.size();

            if (level == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                break;
            }

            for (int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }

                if (parent.count(node) && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }

            level++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
