#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAX 2010
#define endl '\n'

using namespace std;

bool mat[MAX][MAX];
int dp[MAX];

int main()
{
	sws;

	int N;
	string str;

	cin >> N >> str;

	for(int i=0;i<N;i++)
		mat[i][i]=true;

	for(int i=0;i<N-1;i++)
		mat[i][i+1] = (str[i]==str[i+1]);

	for(int i=2;i<N+1;i++)
		for(int j=0;j<N-i;j++)
			mat[j][j+i]=mat[j+1][j+i-1] & (str[j]==str[i+j]);

	for(int i=0;i<N;i++)
	{
		if(mat[0][i])
			dp[i]=1;
		else
		{
			int aux=INF;
			for(int j=0;j<i;j++)
				if(mat[j+1][i] and dp[j]<aux)
					aux=dp[j];
			dp[i]=aux+1;
		}
	}
	cout << dp[N-1] << endl;

	return 0;
}