#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases, numFields; 
    
    cin >> testCases;
    
    for (int i = 0; i < testCases; i++) {
        bool lawnmower = false; // Começa desligado
        
        cin >> numFields;
        
        unordered_map<int, deque<int>> oddEvenMap; 
        long long totalDandelions = 0;
        
        bool hasEven = false, hasOdd = false;
        int value;
        
        for (int j = 0; j < numFields; j++) {
            cin >> value;
            
            // Mapeia todos os pares e todos os ímpares para suas respectivas 
            // listas
            int oddOrEven = value % 2;
            oddEvenMap[oddOrEven].push_back(value);
            
            if (oddOrEven == 0) hasEven = true;
            else hasOdd = true;
        }
        
        // Se há ímpares, o cortador ligará pelo menos uma vez
        if (hasOdd) {
            sort(oddEvenMap[1].begin(), oddEvenMap[1].end());
            
            lawnmower = true;
            
            // Soma a maior quantidade ímpar de dentes-de-leão
            totalDandelions += oddEvenMap[1].back();
            
            // Remove da lista
            oddEvenMap[1].pop_back();
            
            // Se há pares, o cortador deverá cortar todos de uma vez enquanto 
            // está ligado
            if (hasEven) {
                int evenSize = oddEvenMap[0].size();
                
                for (int k = 0; k < evenSize; k++) {
                    totalDandelions += oddEvenMap[0][k];
                }
            }
            
            // Se ainda restarem ímpares, ele pode desligar ou ligar várias vezes
            // O cortador deve desligar na menor quantidade ímpar de dentes-de-leão
            // e ligar na maior (adiciona mais ao total)
            int oddSize = oddEvenMap[1].size();
            
            for (int k = 0; k < oddSize; k++) {
                lawnmower = !lawnmower;
                
                if (lawnmower) {
                    totalDandelions += oddEvenMap[1].back();
                    oddEvenMap[1].pop_back();
                }
            }
            
            cout << totalDandelions << endl;
        }
        // Se não há ímpares, o cortador não liga e portanto não há 
        // dentes-de-leão cortados
        else cout << 0 << endl;
    }
    
    return 0;
}