#include <bits/stdc++.h>
using namespace std;
void line() {
    cout << "\n========================================\n";
}

vector<int> greedy(vector<int> coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    vector<int> res;
    cout << "\n[Greedy Steps]\n";
    for (int coin : coins) {
        while (amount >= coin) {
            cout << "Pick coin " << coin << " | Remaining: " << amount - coin << "\n";
            amount -= coin;
            res.push_back(coin);
        }
    }
    return res;
}

vector<int> dpSolution(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    vector<int> prev(amount + 1, -1);
    dp[0] = 0;
    cout << "\n[DP Table Build]\n";
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                if (dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    prev[i] = coin;
                }
            }
        }
        cout << "dp[" << i << "] = ";
        if (dp[i] == INT_MAX) cout << "INF\n";
        else cout << dp[i] << "\n";
    }
    vector<int> res;
    cout << "\n[Backtracking Optimal Solution]\n";
    while (amount > 0) {
        cout << "Take coin " << prev[amount] << " -> New amount: " << amount - prev[amount] << "\n";
        res.push_back(prev[amount]);
        amount -= prev[amount];
    }
    return res;
}

// PRINT RESULT
void printResult(string name, vector<int> res) {
    cout << "\n" << name << ":\n";
    for (int x : res) cout << x << " ";
    cout << "\nTotal Coins: " << res.size() << "\n";
}

int main() {
    int n, amount;
    line();
    cout << "      COIN CHANGE OPTIMIZER\n";
    line();
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter denominations: ";
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter amount: ";
    cin >> amount;
    line();
    vector<int> g = greedy(coins, amount);
    line();
    vector<int> d = dpSolution(coins, amount);
    line();
    printResult("Greedy Result", g);
    printResult("DP Optimal Result", d);
    line();
    if (g.size() != d.size()) {
        cout << "⚠ Greedy FAILED (Non-canonical coin system)\n";
    } else {
        cout << "✔ Greedy succeeded (Canonical system)\n";
    }
    line();
    return 0;
}