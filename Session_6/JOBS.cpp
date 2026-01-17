#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> leader;

    int getSlot(int d) {
        if (leader[d] == d) return d;
        return leader[d] = getSlot(leader[d]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();

        vector<tuple<int,int>> arr;
        int maxD = 0;

        for (int i = 0; i < n; i++) {
            arr.push_back({profit[i], deadline[i]});
            maxD = max(maxD, deadline[i]);
        }

        sort(arr.begin(), arr.end(), greater<>());

        leader.assign(maxD + 1, 0);
        for (int i = 0; i <= maxD; i++)
            leader[i] = i;

        int jobsDone = 0;
        int profitEarned = 0;

        for (auto &it : arr) {
            int p = get<0>(it);
            int d = get<1>(it);

            int freeSlot = getSlot(d);
            if (freeSlot > 0) {
                jobsDone++;
                profitEarned += p;
                leader[freeSlot] = getSlot(freeSlot - 1);
            }
        }

        return {jobsDone, profitEarned};
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> deadline(n), profit(n);

    for (int i = 0; i < n; i++)
        cin >> deadline[i];

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    vector<int> result = sol.jobSequencing(deadline, profit);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
