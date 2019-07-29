#include <bits/stdc++.h>

#define mod (long long)(1e9 + 7)
#define MAX (long long)(1e4 + 1)
#define ll long long
#define endl '\n'

using namespace std;

ll dp[MAX];

ll calc(ll N)
{
	if(dp[N]==-1)
		dp[N]=(4*calc(N-2)+calc(N-1)+2*calc(N-3))%mod;
	else if(N==0 or N==1)
		return dp[1];
	else if(N==2)
		return dp[2];

	return dp[N];
}

int main ()
{
	ll N;

	cin >> N;

	dp[0]=1;
	dp[1]=1;
	dp[2]=5;

	for(int i=3; i<=N; i++)
		dp[i]=-1;

	cout << calc(N) << endl;

	return 0;
}
