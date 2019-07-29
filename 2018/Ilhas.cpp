#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAX 1010
#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pair<int,int> >
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define endl '\n'

using namespace std;

vector<vii> grafo;
vi distancia;
priority_queue< pii, vii, greater<pii> > fila;

void dikjstra(int S)
{
	priority_queue< pii, vii, greater<pii> > fila;
	int dist, vert, aux;
	distancia[S]=0;

	fila.push(mp(S, 0));

	while(!fila.empty())
	{
		aux = fila.top().f;
		fila.pop();

		forn(i, grafo[aux].size())
		{
			vert=grafo[aux][i].f;
			dist=grafo[aux][i].s;
			if(distancia[vert]>distancia[aux]+dist)
			{
				distancia[vert]=distancia[aux]+dist;
				fila.push(mp(vert, distancia[vert]));
			}
		}
	}
}

int main()
{
	int N, M, a, b, p, S;
	int ma, mi;

	cin >> N >> M;

	distancia.assign(N+1, INF);
	grafo.assign(N+1, vii());
	ma=-1; mi=INF;

	forn(i, M)
	{
		cin >> a >> b >> p;
		grafo[a].pb(mp(b, p));
		grafo[b].pb(mp(a, p));
	}

	cin >> S;

	dikjstra(S);

	for(int i=1;i<=N;i++)
	{
		if(distancia[i]!=INF and distancia[i]!=0)
		{
			ma=max(ma, distancia[i]);
			mi=min(mi, distancia[i]);
		}
	}

	cout << ma - mi << endl;

	return 0;
}
