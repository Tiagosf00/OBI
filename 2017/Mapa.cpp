#include <bits/stdc++.h>
#define MAX 110
#define endl '\n'

using namespace std;

int d[5]={1,0,-1,0,1};
char mat[MAX][MAX];

void DFS(int x, int y)
{
	bool t=true;
	mat[x][y]='.';
	for(int i=0;i<=4;i++)
		if(mat[x+d[i]][y+d[i+1]]=='H')
		{
			t=false;
			DFS(x+d[i], y+d[i+1]);
		}

	if(t)
		cout << x << " " << y << endl;
}

int main()
{
	memset(mat, '.', sizeof(mat));
	int L, C, x, y;

	cin >> L >> C;

	for(int i=1;i<=L;i++)
		for(int j=1;j<=C;j++)
		{
			cin >> mat[i][j];
			if(mat[i][j]=='o')
			{
				x=i;
				y=j;
			}
		}

	DFS(x, y);

	return 0;
}