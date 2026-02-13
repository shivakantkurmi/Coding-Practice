/*
# Intuition
A substring is balanced if all **distinct characters present in it occur the same number of times**.  
Since the string contains only `'a'`, `'b'`, and `'c'`, a balanced substring can be:

1. Only one character (e.g., `"aaa"`)
2. Two characters with equal counts (e.g., `"abba"`)
3. Three characters with equal counts (e.g., `"abcabc"`)

For equal-frequency substring problems, a key trick is using **prefix frequency differences + hashmap**.  
If two prefix states have the same difference, the substring between them is balanced.

---

# Approach

We handle three cases:

### Case 1: Single character
The longest contiguous run of the same character is always balanced.

---

### Case 2: Two-character balance
For each pair among:
- (a,b)
- (a,c)
- (b,c)

A substring is balanced if:
count_x = count_y  
AND the third character count does not change.

So we store states as:
(cx − cy, cz)

If the same state appears again, the substring between them is balanced.

---

### Case 3: All three characters
Balanced means:
a = b = c

We track:
(a − b, a − c)

If this pair repeats, the substring between them is balanced.

---

# Complexity

- **Time complexity:** O(n)  
Each pass over the string is linear and we do a constant number of passes.

- **Space complexity:** O(n)  
Used for hashmap storage of prefix states.


*/


class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;

        // ---------- Case 1: single char ----------
        int run=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) run++;
            else run=1;
            ans=max(ans,run);
        }

        // prefix counts
        vector<int> A(n+1,0),B(n+1,0),C(n+1,0);
        for(int i=0;i<n;i++){
            A[i+1]=A[i];
            B[i+1]=B[i];
            C[i+1]=C[i];

            if(s[i]=='a') A[i+1]++;
            else if(s[i]=='b') B[i+1]++;
            else C[i+1]++;
        }

        // ---------- Case 2: pairs ----------
        auto solvePair=[&](char x,char y,char z){
            map<pair<int,int>,int> mp;
            mp[{0,0}]=0;

            for(int i=1;i<=n;i++){
                int cx=(x=='a'?A[i]:(x=='b'?B[i]:C[i]));
                int cy=(y=='a'?A[i]:(y=='b'?B[i]:C[i]));
                int cz=(z=='a'?A[i]:(z=='b'?B[i]:C[i]));

                pair<int,int> key={cx-cy,cz};

                if(mp.count(key)){
                    ans=max(ans,i-mp[key]);
                }else{
                    mp[key]=i;
                }
            }
        };

        solvePair('a','b','c');
        solvePair('a','c','b');
        solvePair('b','c','a');

        // ---------- Case 3: all three ----------
        map<pair<int,int>,int> mp;
        mp[{0,0}]=0;

        for(int i=1;i<=n;i++){
            pair<int,int> key={A[i]-B[i],A[i]-C[i]};

            if(mp.count(key)){
                ans=max(ans,i-mp[key]);
            }else{
                mp[key]=i;
            }
        }

        return ans;
    }
};
