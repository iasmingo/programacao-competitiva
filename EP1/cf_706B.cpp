#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n_stores; 
    
    cin >> n_stores;
    
    vector<int> prices;
    prices.resize(n_stores);
    
    for (int i = 0; i < n_stores; i++) {
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end());
    
    int q_days; 
    
    cin >> q_days;
    
    int mi_coins;
    
    for (int i = 0; i < q_days; i++) {
        cin >> mi_coins;
        
        auto up = upper_bound(prices.begin(), prices.end(), mi_coins);
        auto numberOfStores = (up - prices.begin());
        
        cout << numberOfStores << endl;
    }

    return 0;
}