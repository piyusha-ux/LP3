#include <iostream>
#include <vector>

int f1(int ind, const std::vector<int>& wt, const std::vector<int>& val, int W) {
    if (ind == 0) {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }
    if (wt[ind] <= W) {
        int include = val[ind] + f1(ind - 1, wt, val, W - wt[ind]);
        int not_include = 0 + f1(ind - 1, wt, val, W);
        return std::max(include, not_include);
    }
    return 0 + f1(ind - 1, wt, val, W);
}

int findMax(const std::vector<int>& wt, const std::vector<int>& val, int W) {
    int n = wt.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++) {
        if (wt[0] <= w) {
            dp[0][w] = val[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w) {
                int include = val[i] + dp[i - 1][w - wt[i]];
                int not_include = 0 + dp[i - 1][w];
                dp[i][w] = std::max(include, not_include);
            } else {
                dp[i][w] = 0 + dp[i - 1][w];
            }
        }
    }

    return dp[n - 1][W];
}

int main() {
    std::vector<int> wt = {15,30,45};
    std::vector<int> val = {60,100,150};
    int W = 50;
    std::cout << findMax(wt, val, W) << std::endl;
    return 0;
}
