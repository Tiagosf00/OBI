#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
	int A, B, K, L;

	cin >> A >> B;

	L = (A-1)*2 + (B-1)*2;
	K = A*B + (A-1)*(B-1);

	cout << K << endl;
	cout << L << endl;

	return 0;
}