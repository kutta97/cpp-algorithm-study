#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string pokemons[100001];
map<string, int> pokemonName;
string quiz;

int main() {
    cin >> N >> M;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string pokemon;
    for (int i = 1; i <= N; i++) {
        cin >> pokemon;
        pokemons[i] = pokemon;
        pokemonName[pokemon] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> quiz;

        int num = atoi(quiz.c_str());   
        if (num != 0) {
            cout << pokemons[num] << '\n';
        } else {
            cout << pokemonName[quiz] << '\n';
        }
    }
    return 0;
}