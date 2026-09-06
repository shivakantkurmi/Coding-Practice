/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;

        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        Node* newHead=new Node(0);
        Node* shiva=newHead;
        temp=head;
        while(temp){
            shiva->next=mp[temp];
            shiva->next->random=mp[temp->random];
            shiva=shiva->next;
            temp=temp->next;
        }
        return newHead->next;


        

    }
};
