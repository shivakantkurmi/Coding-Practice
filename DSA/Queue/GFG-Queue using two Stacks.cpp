/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
void StackQueue::push(int B) {
    s1.push(B);
}

int StackQueue::pop() {
    if(s1.size()==0)return -1;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int x= s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return x;
}
