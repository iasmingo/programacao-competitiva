#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s_string;
    cin >> s_string;
    
    stack<char> s_stack;
    
    for (char c : s_string) {
        s_stack.push(c);
        
        // Remove ABC enquanto possível
        while (s_stack.size() >= 3) {
            char aux3 = s_stack.top(); s_stack.pop();
            char aux2 = s_stack.top(); s_stack.pop();
            char aux1 = s_stack.top(); s_stack.pop();
            
            if (aux1 == 'A' && aux2 == 'B' && aux3 == 'C') {
                // Já removeu, não faz nada
            } 
            else {
                // Não é ABC, recoloca e para
                s_stack.push(aux1);
                s_stack.push(aux2);
                s_stack.push(aux3);
                break;
            }
        }
    }
    
    string result = "";
    while (!s_stack.empty()) {
        result = s_stack.top() + result;
        s_stack.pop();
    }
    cout << result;
    
    return 0;
}