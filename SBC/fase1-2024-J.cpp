#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

// https://maratona.sbc.org.br/hist/2024/primfase24/contest-pf2024/maratona.pdf

struct Edge {
    int to, color, id;
};

struct State {
    int u, cnt, last_color, first_edge_color, edge_idx;
    vector<int> path;
    vector<bool> used;
    
    State(int _u, int _cnt, int _lc, int _fec, int _ei, const vector<int>& _path, const vector<bool>& _used) 
        : u(_u), cnt(_cnt), last_color(_lc), first_edge_color(_fec), edge_idx(_ei), path(_path), used(_used) {}
};

bool dfs_iterative(int start_city, vector<vector<Edge>> &adj, int M) {
    stack<State> st;
    st.push(State(start_city, 0, -1, -1, 0, vector<int>(), vector<bool>(M, false)));
    
    while (!st.empty()) {
        State curr = st.top();
        st.pop();
        
        // Se usamos todas as arestas
        if (curr.cnt == M) {
            if (curr.u == start_city && curr.last_color != curr.first_edge_color) {
                // Encontrou solução, imprimir resultado
                cout << start_city + 1 << "\n";
                for (int i = 0; i < M; ++i) {
                    cout << curr.path[i] << (i + 1 == M ? "\n" : " ");
                }
                return true;
            }
            continue;
        }
        
        // Continuar explorando a partir do edge_idx atual
        for (int i = curr.edge_idx; i < adj[curr.u].size(); ++i) {
            Edge &e = adj[curr.u][i];
            
            if (!curr.used[e.id] && e.color != curr.last_color) {
                // Criar novo estado
                vector<int> new_path = curr.path;
                vector<bool> new_used = curr.used;
                
                new_used[e.id] = true;
                new_path.push_back(e.id + 1);
                
                int new_first_edge_color = curr.first_edge_color;
                if (curr.cnt == 0) {
                    new_first_edge_color = e.color;
                }
                
                // Adicionar estado para backtrack (continuar loop atual)
                if (i + 1 < adj[curr.u].size()) {
                    st.push(State(curr.u, curr.cnt, curr.last_color, curr.first_edge_color, i + 1, curr.path, curr.used));
                }
                
                // Adicionar estado para próximo nível
                st.push(State(e.to, curr.cnt + 1, e.color, new_first_edge_color, 0, new_path, new_used));
                break;
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    vector<vector<Edge>> adj;

    cin >> N >> M >> K;
    adj.resize(N);

    for (int i = 0; i < M; ++i) {
        int I, J, C;
        cin >> I >> J >> C;
        --I; --J;
        adj[I].push_back({J, C, i});
        adj[J].push_back({I, C, i});
    }

    for (int start = 0; start < N; ++start) {
        if (dfs_iterative(start, adj, M)) {
            return 0;
        }
    }
    
    cout << -1 << "\n";
    return 0;
}