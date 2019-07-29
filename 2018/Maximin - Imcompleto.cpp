#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <vector>

using namespace std;

bool comp(int A, int B)
{
	return A<B;
}

int main()
{
	int N, L, R;
	int dif=0, med;
	int papel[100000];

	cin >> N >> L >> R;

	for(int i=0;i<N;i++)
		cin >> papel[i];

	sort(papel, papel+N, comp);

	for(int i=0;i<N;i++)
	{
		if(papel[i]<=L)
		{
			if(i+1==N)
			{
				dif=R-papel[i];
				i=N;
			}else if(papel[i+1]>=L)
			{
				med = (papel[i+1]-papel[i])/2;
				if(papel[i+1]-med>=L and med+papel[i]<=R)
				{
					if(med>dif)
						dif = med;
				}else if(papel[i+1]-med>R)
				{
					if(R-papel[i]>dif)
						dif = R-papel[i];
				}else if(papel[i]+med<L)
				{
					if(papel[i+1]-L>dif)
						dif = papel[i+1]-L;
				}
			}
		}else if(papel[i]>=R)
		{
			if(i==0)
			{
				dif=papel[i]-L;
				i=N;
			}else if(papel[i-1]<=R)
			{
				med = (papel[i]-papel[i-1])/2;
				if(papel[i-1]+med<=R and papel[i]-med>=L)
				{
					if(med>dif)
						dif = med;
				}else if(papel[i]-med<L)
				{
					if(papel[i]-L>dif)
						dif=papel[i]-L;
				}else
				{
					if(R-papel[i-1]>dif)
						dif = R-papel[i-1];
				}
				i=N;
			}
		}else
		{
			if(i==0)
			{
				if(papel[i]-L>dif)
					dif = papel[i]-L;

			}else if(i+1==N)
			{
				if(R-papel[i]>dif)
						dif = R-papel[i];
			}else
			{
				if((papel[i]-papel[i-1])/2>dif)
					dif = (papel[i]-papel[i-1])/2;
			}
		}
	}
	cout << dif << endl;

	return 0;
}