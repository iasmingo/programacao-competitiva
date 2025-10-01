#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t_tests;
    cin >> t_tests;

    for (int i = 0; i < t_tests; i++) {
        int n_students;
        cin >> n_students;

        vector<pair<pair<int, int>, int> studentsTimeAndIndex;

        for (int j = 0; j < n_students; j++) {
            int arriving, waitingTime;
            cin >> arriving >> waitingTime;

            studentsTimeAndIndex.push_back({{arriving, j}, waitingTime});
        }

        sort(studentsTimeAndIndex.begin(), studentsTimeAndIndex.end(), [](auto &a, auto &b){
            return tie(a.first.first, a.first.second) < tie(b.first.first, b.first.second);
        });

        int time = 1;

        for (int j = 0; j < n_students; j++) {
            if (studentsTimeAndIndex[j].first.first + studentsTimeAndIndex.second <= time) {
                cout << time << endl;
                time++;
            }
            else cout << -1 << endl;
        }
    }

    return 0;
}