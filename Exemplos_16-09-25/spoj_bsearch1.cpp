#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, queries;
    
    cin >> n >> queries;
    
    // Alterei de vector para unordered_map porque recebi TLE
    // n <= 10^5; queries <= 5x10^5
    // Complexidade anterior: O(queries x log n) = 500.000 x log(100.000) ~ 8,5 milhões de operações
    // Limite típico: ~10^8 operações/segundo
    // A implementação anterior pode levar ~0,1s, mas tem o problema do overhead
    // Complexidade atual: O(n + queries) -> O(n) na inserção e O(1) na busca
    // map é uma árvore balanceada, unordered_map é uma hash table, por isso a escolha
    unordered_map<int, int> numbers; numbers.reserve(n);
    int value;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        
        // Armazena apenas a primeira ocorrência
        if (numbers.find(value) == numbers.end()) {
            numbers[value] = i;
        }
    }
    
    for (int i = 0; i < queries; i++) {
        int target;
        
        cin >> target;
        
        auto it = numbers.find(target);
        
        // Troquei o endl por '\n'
        // '\n' é adicionado ao buffer interno e não força a escrita no terminal
        // endl quebra a linha e faz flush forçado
        
        // Analogia sem buffer (flush a cada operação): 
        // Cliente 1: "Quero pizza" → Garçom vai para cozinha
        // Cliente 2: "Quero refrigerante" → Garçom vai para cozinha  
        // Cliente 3: "Quero salada" → Garçom vai para cozinha
        
        // Analogia com buffer (comportamento normal):
        // Cliente 1: "Quero pizza" → Garçom ANOTA no bloco
        // Cliente 2: "Quero refrigerante" → Garçom anota no bloco
        // Cliente 3: "Quero salada" → Garçom anota no bloco
        // Quando bloco fica cheio ou no final → Vai de uma vez para cozinha
        if (it != numbers.end()) cout << it->second << '\n';
        else cout << "-1\n";
    }
    
    return 0;
}