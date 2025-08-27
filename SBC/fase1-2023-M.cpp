#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// https://maratona.sbc.org.br/hist/2023/primfase23/contest/maratona.pdf

const int INF = 1e9+7;

vector<int> dijkstra(int src, const vector<vector<int>>& C) {
    int N = C.size();
    vector<int> dist(N, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (int v = 0; v < N; ++v) {
            if (u != v && C[u][v] > 0 && dist[v] > dist[u] + C[u][v]) {
                dist[v] = dist[u] + C[u][v];
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> C[i][j];

    vector<vector<int>> dist(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        dist[i] = dijkstra(i, C);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (dist[i][j] < C[i][j]) {
                cout << -1 << endl;
                return 0;
            }

    int removiveis = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            bool removivel = false;
            for (int k = 0; k < N; ++k) {
                if (k != i && k != j && 
                    dist[i][k] + dist[k][j] == C[i][j]) {
                    removivel = true;
                    break;
                }
            }
            if (removivel) removiveis++;
        }
    }
    cout << removiveis << endl;
    return 0;
}