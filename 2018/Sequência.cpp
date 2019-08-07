#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAX 100010
#define pb push_back
#define endl '\n'

using namespace std;

int dp[MAX][21];
vector<int> vet;
vector<bool> mark;

int main()
{
	int N, L, H, aux, resp=-INF;

	cin >> N >> L >> H;

	memset(dp, -INF, sizeof(dp));

	for(int i=0;i<N;i++)
	{
		cin >> aux;
		vet.pb(aux);
	}

	for(int i=0;i<N;i++)
	{
		cin >> aux;
		mark.pb(aux);
	}

	if(mark[0])
	{
		dp[0][0]=0;
		dp[0][1]=vet[0];
	}else
		dp[0][0]=max(0, vet[0]);

	for(int i=1;i<N;i++)
	{
		if(mark[i])
			dp[i][0]=0;
		else
			dp[i][0]=max(0, dp[i-1][0]+vet[i]);

		if(L==0)
			resp=max(resp, dp[i][0]);

		for(int j=1;j<=H;j++)
		{
			if(mark[i])
				dp[i][j]=dp[i-1][j-1]+vet[i];
			else
				dp[i][j]=dp[i-1][j]+vet[i];

			if(j>=L and j<=H)
				resp=max(resp, dp[i][j]);
		}
	}

	cout << resp << endl;

	return 0;
}