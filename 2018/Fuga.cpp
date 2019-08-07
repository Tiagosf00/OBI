#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, M, xs, ys, xe, ye;
int resp = 0;
char mapa[20][20];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void dfs(int x, int y, int dist)
{
	if(x==xs and y==ys)
		resp = max(resp, dist);
	else
	{
		int aux[4]; //Armazena informações do mapa antigo para que as chamadas recursivas funcionem
		for(int i=0;i<4;i++)
			aux[i] = mapa[x+dx[i]][y+dy[i]];
		for(int i=0;i<4;i++)
		{
			if(mapa[x+dx[i]][y+dy[i]]==' ')
			{
				for(int j=0;j<4;j++)
					mapa[x+dx[j]][y+dy[j]]='#';
				mapa[x][y]='#';

				dfs(x+dx[i], y+dy[i], dist+1);

				for(int j=0;j<4;j++)
					mapa[x+dx[j]][y+dy[j]]=aux[j];
			}
		}
	}
}


int main()
{
	cin >> N >> M >> xe >> ye >> xs >> ys;

	memset(mapa, ' ', sizeof(mapa));
	for(int i=0; i<=N+1;i++)
		for(int j=0; j<=M+1;j++)
			if(i==0 or i==N+1 or j==0 or j==M+1 or (j%2==0 and i%2==0))
				mapa[i][j]='#';

	dfs(xe, ye, 1);

	cout << resp << endl;

	return 0;
}