#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int L, C;
    scanf("%d %d", &L, &C);

    int t1 = L*C + (L-1)*(C-1);
    int t2 = 2*(L-1) + 2*(C-1);

    printf("%d\n", t1);
    printf("%d\n", t2);

    return 0;
}