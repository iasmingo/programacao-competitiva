#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    
    cin >> testCases;
    
    for (int i = 0; i < testCases; i++) {
        int n;
        
        cin >> n;
        
        vector<int> numbers(2*n);
        
        for (int j = 0; j < 2*n; j++) {
            cin >> numbers[j];
        }
        
        sort(numbers.begin(), numbers.end());
        
        int total = 0;
        
        for (int j = ((2*n) - 2); j >= 0; j = j - 2) {
            total += numbers[j];
        }
        
        cout << total << endl;
    }
    
    return 0;
}