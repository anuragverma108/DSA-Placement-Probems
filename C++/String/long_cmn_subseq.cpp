#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the LCS and reconstruct the sequence
int findLCS(const string& str1, const string& str2, string& lcs) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D table to store the length of LCS for substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table to find the length of LCS
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS sequence
    int lcsLength = dp[m][n];
    lcs.resize(lcsLength);
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[lcsLength - 1] = str1[i - 1];
            i--;
            j--;
            lcsLength--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    string lcs;
    int length = findLCS(str1, str2, lcs);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS Sequence: " << lcs << endl;

    return 0;
}
