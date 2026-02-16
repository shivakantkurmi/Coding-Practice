vector<int> Smallestonleft(int arr[], int n) {
    // code here
    vector<int> ans;
    set<int> s;
    
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(arr[i]);
        // lower_bound(x) Gives first element ≥ x
        
        
        if(it == s.begin()){
            ans.push_back(-1);
        }
        else{
            //since we want strictly smaller but greatest among them so we iterate a step back so we 
            // can found the value which is x<arr[i] but x greatest among all xi:xi<arr[i]
            --it;
            ans.push_back(*it);
        }
        
        s.insert(arr[i]);
    }
    
    return ans;
}
