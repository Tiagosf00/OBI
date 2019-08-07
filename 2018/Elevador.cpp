#include <bits/stdc++.h>

#define pb push_back
#define vi vector<int>
#define endl '\n'

using namespace std;

int main()
{
	int N, aux;
	bool t=true;
	vi vet;

	cin >> N;

	vet.pb(0);

	for(int i=0;i<N;i++)
	{
		cin >> aux;
		vet.pb(aux);
	}

	sort(vet.begin(), vet.end());

	for(int i=1;i<(int)vet.size() and t;i++)
		if(vet[i]-vet[i-1]>8)
			t=false;

	if(t)
		cout << "S\n";
	else
		cout << "N\n";

	return 0;
}