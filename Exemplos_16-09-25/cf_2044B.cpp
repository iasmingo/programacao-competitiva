#include <bits/stdc++.h>

#define endl '\n'
#define long long ll

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests; cin >> tests;
    
    for (int i = 0; i < tests; i++) {
        string s; cin >> s;
        
        int size = s.size();
        
        for (int j = size - 1; j >= 0; j--) {
            if (s[j] == 'p') cout << "q";
            else if (s[j] == 'q') cout << "p";
            else cout << s[j];
        }
        
        cout << endl;
    }

    return 0;
}