class Solution {
public:
    int minimumStep(int n) {
        int steps = 0;

        while (n > 1) {
            if (n % 3 == 0) {
                // Reverse the operation x -> 3*x
                n /= 3;
            } else {
                // Reverse the operation x -> x + 1
                n--;
            }

            steps++;
        }

        return steps;
    }
};
