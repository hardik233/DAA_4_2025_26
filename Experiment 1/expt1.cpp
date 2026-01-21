#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long opCount = 0;
int currentDepth = 0, maxDepth = 0;

void complexRec(int n) {
    opCount++; currentDepth++;
    maxDepth = max(maxDepth, currentDepth);

    opCount++;
    if (n <= 2) { currentDepth--; return; }

    int p = n; opCount++;
    vector<int> temp(n);

    while (p > 0) {
        opCount++;
        opCount++;

        for (int i = 0; i < n; i++) {
            opCount++;
            temp[i] = i ^ p;
            opCount++;
        }

        p >>= 1; opCount++;
    }
    opCount++;

    vector<int> small(n); opCount++;
    for (int i = 0; i < n; i++) {
        opCount++;
        small[i] = i * i;
        opCount++;
    }

    opCount++;
    reverse(small.begin(), small.end()); opCount++;

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    currentDepth--;
}

int main() {
    int n = 64;

    auto start = high_resolution_clock::now();
    complexRec(n);
    auto end = high_resolution_clock::now();

    cout << opCount << endl;
    cout << maxDepth << endl;
    cout << duration_cast<milliseconds>(end - start).count() << endl;
}
