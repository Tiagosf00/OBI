#include <bits/stdc++.h>
#define pii pair<int, int>

const int INF = 1e9;

using namespace std;

vector<vector<pii>> grafo(1010, vector<pii>());

vector<int> dijkstra(int S){
    vector<int> d(1010, INF);
    vector<bool> visto(1010, false);

    priority_queue< pii, vector<pii>, greater<pii> > fila;

    d[S] = 0;
    fila.push({0, S});

    while(!fila.empty()){
        // 1º passo
        int u = fila.top().second;
        fila.pop();

        // 2º passo
        if(visto[u]==true) continue;
        visto[u]=true;

        // 3º passo
        for(auto g: grafo[u]){
            int v = g.first;
            int p = g.second;

            if(d[u] + p < d[v]){
                d[v] = d[u] + p;
                fila.push({d[v], v});
            }
        }
    }

    return d;
}

int main()
{
    int N, M, u, v, p;
    cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> u >> v >> p;
        grafo[u].push_back({v, p});
        grafo[v].push_back({u, p});
    }

    int S;
    cin >> S;

    vector<int> distancia = dijkstra(S);

    int ma=0, mi=INF;

    for(int i=1;i<=N;i++){
        if(i!=S){
            ma = max(ma, distancia[i]);
            mi = min(mi, distancia[i]);
        }
    }

    cout << ma - mi << endl;

    return 0;
}