/*
// structure of the node is as follows

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        set<int> temp;
        while(head1!=nullptr){
            temp.insert(head1->data);
            head1=head1->next;
        }
        while(head2!=nullptr){
            temp.insert(head2->data);
            head2=head2->next;
        }
        Node* dummy=new Node(0);
        Node* ans=dummy;
        for(int i:temp){
            dummy->next=new Node(i);
            dummy=dummy->next;
        }
        return ans->next;
        
    }
};
