class Solution {
public:
    
    unordered_map<string,int> mp;
    string solve(int n, string& x){
        if(n==x.length()){ if( mp.find(x)==mp.end()) return x ;
        else return "";
        }
        for(int i=0;i<2;i++){
            x+=to_string(i);
            string y =solve(n,x);
            if(y!="") return x;
            x.pop_back();
        }
        return "";
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto i:nums) mp[i]++;
        int n=nums.size();
        string s="";
        return solve(n,s);
    }
};
