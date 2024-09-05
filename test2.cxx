
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<tuple<int, int, int>> squadrons(M); // (time, left, right)
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        squadrons[i] = make_tuple(t, a, b);
    }

    sort(squadrons.begin(), squadrons.end());

    int safeLeft = 0, safeRight = N;
    int currentTime = 0;

    for (const auto& [time, left, right]: squadrons) {
        // Adjust the safe range based on time and Oli's movement capability
        int delta = (time - currentTime) * K;
        safeLeft = max(0, safeLeft - delta);
        safeRight = min(N, safeRight + delta);
        currentTime = time;

        // Update the safe zone if it's affected by the squadron
        if (!(safeRight < left || safeLeft > right)) {
            if (safeLeft >= left && safeRight <= right) {
                cout << "NO" << endl;
                return 0;
            }

            if (safeLeft < left) safeRight = min(safeRight, left - 1);
            if (safeRight > right) safeLeft = max(safeLeft, right + 1);
        }cout << safeLeft << ", " << safeRight << "\n";

        // Check if Oli is trapped
        if (safeLeft > safeRight) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
