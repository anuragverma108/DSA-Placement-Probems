#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a stock
struct Stock {
    string name;
    double returns;
    double risk;
};

// Function to find the optimal allocation of the budget
void optimizePortfolio(vector<Stock>& stocks, double budget, double riskThreshold) {
    int n = stocks.size();
    
    // Create a dynamic programming table to store the maximum returns for a given budget and risk threshold
    vector<vector<double>> dp(n + 1, vector<double>(int(budget) + 1, 0.0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= int(budget); j++) {
            dp[i][j] = dp[i - 1][j]; // The option of not investing in the current stock
            
            // Check if there is budget to invest in the current stock
            if (j >= int(stocks[i - 1].risk)) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - int(stocks[i - 1].risk)] + stocks[i - 1].returns);
            }
        }
    }
    
    // Reconstruct the optimal portfolio allocation
    vector<int> allocation(n, 0);
    int i = n, j = int(budget);
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            allocation[i - 1] = 1; // Invest in the current stock
            j -= int(stocks[i - 1].risk);
        }
        i--;
    }
    
    // Output results
    cout << "Optimal portfolio allocation:" << endl;
    for (int i = 0; i < n; i++) {
        if (allocation[i] == 1) {
            cout << stocks[i].name << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Stock> stocks = {
        {"Stock A", 0.08, 0.12},
        {"Stock B", 0.12, 0.18},
        {"Stock C", 0.15, 0.20},
        {"Stock D", 0.10, 0.15}
    };
    double budget = 10000.0;
    double riskThreshold = 0.25;

    optimizePortfolio(stocks, budget, riskThreshold);

    return 0;
}
