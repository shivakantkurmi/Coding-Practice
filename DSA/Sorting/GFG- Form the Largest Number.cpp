class Solution {
  public:
    string findLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            string str_a = to_string(a);
            string str_b = to_string(b);
            return (str_a + str_b) > (str_b + str_a);
        });
        if (arr[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : arr) {
            ans += to_string(num);
        }
        return ans;
    }
};
