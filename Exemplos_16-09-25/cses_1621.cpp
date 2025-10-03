#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    
    cin >> n;
    
    set<int> unique;
    int value;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        unique.insert(value);
    }
    
    cout << unique.size() << endl;
    
    return 0;
}