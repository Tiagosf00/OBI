#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define vi vector<int>

#define endl '\n'

using namespace std;

int main()
{
	int N, resp=2, var=2, aux;
	vi vet;
	map<int, int> mapa;

	cin >> N;

	vet.pb(0);

	for(int i=0;i<N;i++)
	{
		cin >> aux;
		if(vet.back()!=aux)
			vet.pb(aux);
	}
	vet.pb(0);
	
	for(int i=1;i<(int)vet.size()-1;i++)
	{
		if(vet[i-1]>vet[i] and vet[i+1]>vet[i])
			mapa[vet[i]]--;
		else if(vet[i-1]<vet[i] and vet[i+1]<vet[i])
			mapa[vet[i]]++;
	}

	for(map<int, int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
	{
		var-=it->s;
		resp=max(resp, var);
	}
	cout << resp << endl;

	return 0;
}