#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> sortedList;
    vector<int> answer(n);

    for (int idx = 0; idx < n; idx++) {
        int x;
        cin >> x;

        int left = 0, right = sortedList.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (sortedList[mid] <= x)
                left = mid + 1;
            else
                right = mid;
        }

        sortedList.insert(sortedList.begin() + left, x);

        if (idx + 1 < k)
            answer[idx] = -1;
        else
            answer[idx] = sortedList[sortedList.size() - k];
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
