#include <bits/stdc++.h>

#define endl '\n'
#define MAX (int)(1e4+1)

using namespace std;

int main()
{
	int N, num, total;
	int D[MAX], E[MAX];
	char aux;

	memset(D, 0, sizeof(D));
	memset(E, 0, sizeof(E));
	total=0;
	
	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> num >> aux;
		if(aux=='D')
		{
			if(E[num]>0)
			{
				E[num]--;
				total++;
			}else
			{
				D[num]++;
			}
		}else if(aux=='E')
		{
			if(D[num]>0)
			{
				D[num]--;
				total++;
			}else
			{
				E[num]++;
			}
		}
	}

	cout << total << endl;

	return 0;
}