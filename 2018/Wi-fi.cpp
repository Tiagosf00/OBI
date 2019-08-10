#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define endl '\n'

using namespace std;

typedef struct
{
	int x, yf, yi;
	bool abrir;
} evento;

bool comp(evento A, evento B)
{
	return A.x < B.x;
}

vector<evento> vet;

int main()
{
	int N, x1, x2, y1, y2, total=0;
	map<int, bool> mapa;

	cin >> N;

	forn(i, N)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		vet.pb((evento){x1, y1, y2, true});
		vet.pb((evento){x2, y1, y2, false});
	}

	sort(vet.begin(), vet.end(), comp);

	for(int i=0;i<(int)vet.size();i++)
	{
		if(vet[i].abrir)
		{
			mapa[vet[i].yi]=true;
			mapa[vet[i].yf]=false;
		}else
		{
			if(mapa[vet[i].yi]==true)
				total++;

			map<int, bool>::iterator it = mapa.find(vet[i].yi);
			--it;
			it->s = false;

			mapa.erase(vet[i].yi);
			mapa.erase(vet[i].yf);
		}
	}

	cout << total << endl;

	return 0;
}