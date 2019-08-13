#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define vi vector<int>
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define endl '\n'

using namespace std;

int main()
{
	int N, L, R, aux, resp=0;
	vi vet;

	cin >> N >> L >> R;

	forn(i, N)
	{
		cin >> aux;
		vet.pb(aux);
	}

	sort(vet.begin(), vet.end());

	resp=max(resp, vet[0]-L);
	resp=max(resp, R-vet[N-1]);
	for(int i=1;i<N;i++)
	{
		int med = (vet[i]+vet[i-1])/2;
		if(med>=L and med<=R)
			resp=max(resp, min(med-vet[i-1], vet[i]-med));
		else if(med<L and vet[i]>L)
			resp=max(resp, min(L-vet[i-1], vet[i]-L));
		else if(med>R and vet[i-1]<R)
			resp=max(resp, min(R-vet[i-1], vet[i]-R));
	}

	cout << resp << endl;

	return 0;
}