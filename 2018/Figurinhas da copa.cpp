#include <bits/stdc++.h>

#define MAX 110
#define pb push_back

using namespace std;

int main()
{
	int N, C, M, total=0, aux;
	vector<int> vet;
	vector<bool> ver(MAX, false);

	cin >> N >> C >> M;

	for(int i=0;i<C;i++)
	{
		cin >> aux;
		vet.pb(aux);
	}

	for(int i=0;i<M;i++)
	{
		cin >> aux;
		ver[aux]=true;
	}

	for(int i=0;i<C;i++)
		if(ver[vet[i]])
			total++;

	cout << C - total << endl;

	return 0;
}