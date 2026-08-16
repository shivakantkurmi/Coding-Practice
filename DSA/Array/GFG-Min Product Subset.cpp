class Solution {
    public:
      int minProd(vector<int>& arr) {
          int negativeCount = 0;
          int smallestPositive = INT_MAX;
          int smallestAbsNegative = INT_MAX;
          long long product = 1;
          bool hasZero = false;

          for (int x : arr) {
              if (x == 0) {
                  hasZero = true;
                  continue;
              }

              product *= x;

              if (x < 0) {
                  negativeCount++;
                  smallestAbsNegative = min(
                      smallestAbsNegative, -x
                  );
              } else {
                  smallestPositive = min(
                      smallestPositive, x
                  );
              }
          }

          if (negativeCount == 0) {
              if (hasZero) {
                  return 0;
              }

              return smallestPositive;
          }

          if (negativeCount % 2 == 0) {
              product /= -smallestAbsNegative;
          }

          return (int)product;
      }
  };
