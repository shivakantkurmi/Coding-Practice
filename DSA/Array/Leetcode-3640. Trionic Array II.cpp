class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix_sum(n,0);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix_sum[i]=(nums[i]+prefix_sum[i-1]);
        int l=-1,p=-1,q=-1;
        int i=1;

        vector<int> p_index(n);
        p_index[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                p_index[i]=p_index[i+1];
            else
                p_index[i]=i;
        }
        
        
        vector<int> q_index(n);
        q_index[0]=0;
        q_index[n-1]=n-1;

        for(int i=n-2;i>0;i--)
        {
            if(nums[i]>nums[i+1])
                q_index[i]=q_index[i+1];
            else
                q_index[i]=i;
        }
        long long sum=LLONG_MIN;
        for(int i=0;i<(n-3);i++)
        {

            int p=p_index[i];
            int q=q_index[p];
            int r=p_index[q];
            //cout<<i<<" "<<p<<" "<<q<<" "<<r<<endl; 
            if(p>i && q>p && p>0 && q<(n-1) && r>q)
            {
                 
                if((prefix_sum[r]-prefix_sum[q])<nums[q+1])
                    sum=max(sum,(prefix_sum[q+1]-prefix_sum[i]+nums[i]));
                else
                    sum=max(sum,(prefix_sum[r]-prefix_sum[i]+nums[i]));
            }
        }
        return sum;
    }
};
