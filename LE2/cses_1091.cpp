#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n_tickets, m_customers;
    cin >> n_tickets >> m_customers;
    
    multiset<int> tickets;
    
    int price;
    
    for (int i = 0; i < n_tickets; i++) {
        cin >> price;
        tickets.insert(price);
    }
    
    int customer;
    
    for (int i = 0; i < m_customers; i++) {
        cin >> customer;
        
        // Encontra o primeiro valor maior do que o valor máximo que o
        // cliente está disposto a pagar
        auto it = tickets.upper_bound(customer);
        
        // Se it for o primeiro elemento, todos os ingressos são mais caros do
        // que o valor máximo que o cliente está disposto a pagar
        // Caso contrário, voltamos uma posição
        if (it == tickets.begin()) {
            cout << -1 << endl;
        } 
        else {
            --it;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    
    return 0;
}