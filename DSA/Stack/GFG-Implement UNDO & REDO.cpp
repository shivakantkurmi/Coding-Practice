//Link : https://www.geeksforgeeks.org/problems/implement-undo-redo/1


class Solution {
  public:
  
    stack<char> doc;
    stack<char> undone;
    void append(char x) {
        // append x into document
        doc.push(x);
    }

    void undo() {
        // undo last change
        char x=doc.top();
        doc.pop();
        undone.push(x);
    }

    void redo() {
        // redo changes
        doc.push(undone.top());
        undone.pop();
    }

    string read() {
        // read the document
        string s;
        stack<char> temp = doc;
        
        while(!temp.empty()){
            s.push_back(temp.top());
            temp.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
