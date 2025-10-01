#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n_tests;

    cin >> n_tests;

    for (int i = 0; i < n_tests; i++) {
        int battlefields, greenLemmings, blueLemmings;

        cin >> battlefields >> greenLemmings >> blueLemmings;

        priority_queue<int> powerGL, powerBL;

        for (int j = 0; j < greenLemmings; j++) {
            int power;
            cin >> power;
            powerGL.push(power);
        }

        for (int j = 0; j < blueLemmings; j++) {
            int power;
            cin >> power;
            powerBL.push(power);
        }

        while (!powerGL.empty() and !powerBL.empty()) {
            // É necessário armazenar os sobreviventes num vetor para dar push somente ao final de TODAS as batalhas
            // Caso contrário, corre-se o risco de um lemming lutar mais de uma vez no mesmo round de batalhas
            vector<int> greenSurvivors, blueSurvivors;
            int fights = min({battlefields, (int)powerGL.size(), (int)powerBL.size()});

            for (int j = 0; j < fights; j++) {

                int greenTop = powerGL.top(); powerGL.pop();
                int blueTop = powerBL.top(); powerBL.pop();

                if (greenTop > blueTop) {
                    greenSurvivors.push_back(greenTop - blueTop);
                }
                else if (greenTop < blueTop) {
                    blueSurvivors.push_back(blueTop - greenTop);
                }
                // Se forem iguais, ambos morrem
            }

            for (int x : greenSurvivors) powerGL.push(x);
            for (int x : blueSurvivors)  powerBL.push(x);
        }

        if (powerGL.empty() and powerBL.empty()) cout << "green and blue died" << endl;
        else if (powerGL.empty()) {
            cout << "blue wins" << endl;

            while (!powerBL.empty()) {
                cout << powerBL.top() << endl;
                powerBL.pop();
            }
        }
        else {
            cout << "green wins" << endl;

            while (!powerGL.empty()) {
                cout << powerGL.top() << endl;
                powerGL.pop();
            }
        }

        if (i != n_tests - 1) cout << endl;
    }
    
    return 0;
}