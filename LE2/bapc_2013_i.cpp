#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t_tests;
    
    cin >> t_tests;
    
    for (int i = 0; i < t_tests; i++) {
        int n_attributes;
        
        cin >> n_attributes;
        
        map<string, vector<string>> categoryToAttributes;
        string attribute, category;
        
        for (int j = 0; j < n_attributes; j++) {
            cin >> attribute >> category;
            
            categoryToAttributes[category].push_back(attribute);
        }
        
        int total = 1;
        
        for (auto it = categoryToAttributes.begin(); it != categoryToAttributes.end(); it++) {
            total *= it->second.size() + 1;
        }
        
        cout << total-1 << endl;
    }
    
    return 0;
}