#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n_players, k_points, q_correctAnswers;
    
    cin >> n_players >> k_points >> q_correctAnswers;
    
    vector<int> score(n_players + 1, 0);
    int player;
    
    // O vector armazena a quantidade de acertos de cada jogador
    for (int i = 0; i < q_correctAnswers; i++) {
        cin >> player;                              
        score[player]++;
    }
    
    // A pontuação final de cada jogador é calculada subtraindo-se:
    // pontuação inicial - (qtd_acertos_geral - qtd_acertos_jogador))
    for (int i = 1; i < n_players + 1; i++) {
        if (k_points - (q_correctAnswers - score[i]) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}