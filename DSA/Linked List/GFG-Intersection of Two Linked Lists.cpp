/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_map<int,int> mp;
        Node *t1=head2,*t2=head1;
        while(t1!=nullptr){
            mp[t1->data]++;
            t1=t1->next;
        }
        Node* dummy=new Node(0);
        Node* ans=dummy;
        while(t2!=nullptr){
            if(mp.find(t2->data)!=mp.end()){
                Node* newNode=new Node(t2->data);
                dummy->next=newNode;
                dummy=dummy->next;
            }
            t2=t2->next;
        }
        return ans->next;
    }
};
