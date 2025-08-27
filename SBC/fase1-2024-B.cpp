#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// https://maratona.sbc.org.br/hist/2024/primfase24/contest-pf2024/maratona.pdf

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> film_to_actors(N + 1); 
    vector<vector<int>> actor_to_films(M + 1); 

    for (int i = 1; i <= N; ++i) {
        int ni;
        cin >> ni;
        film_to_actors[i].resize(ni);
        for (int j = 0; j < ni; ++j) {
            int actor;
            cin >> actor;
            film_to_actors[i][j] = actor;
            actor_to_films[actor].push_back(i);
        }
    }

    int Q;
    cin >> Q;
    cout << "\n";
    while (Q--) {
        int x, y;
        cin >> x >> y;
        queue<pair<int, int>> q;
        vector<bool> visited_actor(M + 1, false);
        vector<bool> visited_film(N + 1, false);
        unordered_map<int, pair<int, int>> parent;

        visited_actor[x] = true;
        q.push({x, -1});

        bool found = false;
        int last_actor = -1, last_film = -1;

        while (!q.empty() && !found) {
            auto [cur_actor, via_film] = q.front(); q.pop();

            for (int film : actor_to_films[cur_actor]) {
                if (!visited_film[film]) {
                    visited_film[film] = true;
                    for (int next_actor : film_to_actors[film]) {
                        if (!visited_actor[next_actor]) {
                            visited_actor[next_actor] = true;
                            parent[next_actor] = {cur_actor, film};
                            q.push({next_actor, film});
                            if (next_actor == y) {
                                found = true;
                                last_actor = next_actor;
                                last_film = film;
                                break;
                            }
                        }
                    }
                }
                if (found) break;
            }
        }

        if (!found) {
            cout << "-1\n";
        } else {
            vector<int> actors;
            vector<int> films;
            int cur = last_actor;
            while (cur != x) {
                actors.push_back(cur);
                films.push_back(parent[cur].second);
                cur = parent[cur].first;
            }
            actors.push_back(x);
            reverse(actors.begin(), actors.end());
            reverse(films.begin(), films.end());

            cout << actors.size() << "\n";
            for (size_t i = 0; i < actors.size(); ++i) {
                cout << actors[i];
                if (i < films.size()) cout << " " << films[i];
                if (i + 1 < actors.size()) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}