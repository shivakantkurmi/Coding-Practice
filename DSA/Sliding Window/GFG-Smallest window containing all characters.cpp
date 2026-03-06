class Solution {
public:
    string minWindow(string &s, string &p) {
        vector<int> mp1(26,0);
        for(char c : p) mp1[c-'a']++;

        int l = 0;
        int start = 0;
        int minLen = INT_MAX;

        vector<int> mp3(26,0);
        int count = 0;
        int required = p.size();

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(mp1[c-'a'] > 0) {
                mp3[c-'a']++;
                if(mp3[c-'a'] <= mp1[c-'a'])
                    count++;
            }

            while(count == required) {
                if(i - l + 1 < minLen) {
                    minLen = i - l + 1;
                    start = l;
                }

                char left = s[l];

                if(mp1[left-'a'] > 0) {
                    mp3[left-'a']--;
                    if(mp3[left-'a'] < mp1[left-'a'])
                        count--;
                }

                l++;
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
