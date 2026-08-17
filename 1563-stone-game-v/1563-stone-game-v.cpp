class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[i][j] = maximum score from i to j
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue, prefix, dp);
    }

private:
    int solve(int i, int j,
              vector<int>& stoneValue,
              vector<int>& prefix,
              vector<vector<int>>& dp) {

        // Only one stone
        if (i >= j)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        int leftSum = 0;
        int rightSum = prefix[j + 1] - prefix[i];

        for (int k = i; k < j; k++) {

            // Add current stone to left
            leftSum += stoneValue[k];

            // Remove current stone from right
            rightSum -= stoneValue[k];

            // Left side is smaller
            if (leftSum < rightSum) {

                // Pruning
                if (ans >= leftSum * 2)
                    continue;

                ans = max(
                    ans,
                    leftSum + solve(i, k, stoneValue, prefix, dp)
                );
            }

            // Right side is smaller
            else if (leftSum > rightSum) {

                // Pruning
                if (ans >= rightSum * 2)
                    break;

                ans = max(
                    ans,
                    rightSum + solve(k + 1, j, stoneValue, prefix, dp)
                );
            }

            // Both sides are equal
            else {

                ans = max({
                    ans,
                    leftSum + solve(i, k, stoneValue, prefix, dp),
                    rightSum + solve(k + 1, j, stoneValue, prefix, dp)
                });
            }
        }

        return dp[i][j] = ans;
    }
};