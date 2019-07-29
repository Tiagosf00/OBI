#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
	int D, N, A;

	cin >> N >> D >> A;

	if(D>=A)
		cout << D-A << endl;
	else
		cout << N-(A-D) << endl;


	return 0;
}