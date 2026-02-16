
class Solution {
  public:
    string secFrequent(string arr[], int n) {
        // code here.
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)mp[arr[i]]++;
        int max=INT_MIN,smax=0;
        string s1,s2;
        for(auto i:mp){
            if(i.second>max){
                smax=max;
                max=i.second;
                s2=s1;
                s1=i.first;
            }
            else if(i.second>smax){
                smax=i.second;
                s2=i.first;
            }
        }
        return s2;
    }
};
