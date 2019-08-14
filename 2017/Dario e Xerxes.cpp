#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool dwin[4][4];

int main()
{
	int N, x, d, total=0;

	cin >> N;

	for(int i=0;i<=4;i++)
		for(int j=i+1;j<i+3;j++)
			dwin[i][j%5]=true;

	for(int i=0;i<N;i++)
	{
		cin >> d >> x;
		total+=dwin[d][x];
	}
	if(2*total>N)
		cout << "dario\n";
	else
		cout << "xerxes\n";

	return 0;
}