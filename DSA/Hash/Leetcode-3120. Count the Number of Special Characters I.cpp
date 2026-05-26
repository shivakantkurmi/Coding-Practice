class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> l(26,0),u(26,0);
        
        for(char c:word){
            if(islower(c)) l[c-'a']=1;
            else u[c-'A']=1;
        }
        
        int ans=0;
        
        for(int i=0;i<26;i++){
            if(l[i] && u[i]) ans++;
        }
        
        return ans;
    }
};
