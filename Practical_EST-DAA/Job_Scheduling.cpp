#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, dead, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int deadline[] = {4, 1, 1, 1};
    int profit[] = {20, 10, 40, 30};
    int n = 4;

    Job arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].id = i;
        arr[i].dead = deadline[i];
        arr[i].profit = profit[i];
    }

    sort(arr, arr + n, cmp);

    int maxDead = 0;
    for (int i = 0; i < n; i++)
        maxDead = max(maxDead, arr[i].dead);

    int slot[maxDead + 1];
    for (int i = 0; i <= maxDead; i++)
        slot[i] = -1;

    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                count++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << count << " " << totalProfit;
    return 0;
}