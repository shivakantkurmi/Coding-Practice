class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double answer=0;
        vector<pair<double,int>>arr;
        for(int i=0;i<val.size();i++){
            double d=(double)val[i]/wt[i];
            arr.push_back({d,wt[i]});
        }
        sort(arr.begin(),arr.end(),greater<pair<double,int>>());
        for(auto p:arr){
            double d=p.first;
            if(capacity>=p.second){
                answer+=d*p.second;
                capacity-=p.second;
            }
            else{
                answer+=((d*capacity));
                break;
            }
        }
        return answer;
    }
};
