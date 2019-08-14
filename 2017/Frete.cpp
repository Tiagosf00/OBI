#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pair<int,int> >
#define endl '\n'

using namespace std;

vector<vii> grafo;
vi dist;
priority_queue< pii, vii, greater<pii> > fila; //(vert, dist)

void dijkstra(int k)
{
	dist[k]=0;
	fila.push(mp(k, 0));

	while(!fila.empty())
	{
		int aux=fila.top().f;
		fila.pop();
		for(int i=0;i<(int)grafo[aux].size();i++)
		{
			int v=grafo[aux][i].f;
			int d=grafo[aux][i].s;
			if(dist[v]>dist[aux]+d)
			{
				dist[v]=dist[aux]+d;
				fila.push(mp(v, dist[v]));
			}
		}
	}
}

int main()
{
	int N, M, A, B, C;

	cin >> N >> M;
	grafo.assign(N+1, vii());
	dist.assign(N+1, INF);

	for(int i=0;i<M;i++)
	{
		cin >> A >> B >> C;
		grafo[A].pb(mp(B,C));
		grafo[B].pb(mp(A,C));
	}

	dijkstra(1);

	cout << dist[N] << endl;

	return 0;
}