/*Structure of a Tree Node
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
    unordered_map<string, int> mp;
    bool ans = false;

    string dfs(Node* root) {
        if (!root) return "$";
        
        //traverse tree in POST OREDR (LEFT->RIGHT->ROOT)
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        //Serialize the subtree
        string cur = to_string(root->data) + "," + left + "," + right;

        // Ignore leaf nodes
        if (root->left || root->right) {
            mp[cur]++;
            
            //if TWO serialized Subtree have same serialization they are same 
            if (mp[cur] == 2)
                ans = true;
        }

        return cur;
    }

public:
    bool dupSub(Node *root) {
        dfs(root);
        return ans;
    }
};
