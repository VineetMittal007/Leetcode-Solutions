class Solution {
private:
    int memoization(int index, int k, int size, vector<int>&houses, vector<vector<int>>&dp)
    {
        if(k == 1)
        {
            int average = houses[((size - index) / 2) + index];
            int ans = 0;
            for(int i = index; i < size; ++i)
            {
                ans += abs(houses[i] - average);
            }
            return ans;
        }
        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }
        int mini = INT_MAX;
        for(int i = index; i <= (size - k); ++i)
        {
            int average = houses[((i - index) / 2) + index];
            int currAns = 0;
            for(int j = index; j <= i; ++j)
            {
                currAns += abs(houses[j] - average);
            }
            int ans = currAns + memoization(i + 1, k - 1, size, houses, dp);
            mini = min(mini, ans);
        }
        return dp[index][k] = mini;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        int size = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>>dp(size, vector<int>(k + 1, -1));
        return memoization(0, k, size, houses, dp);
    }
};