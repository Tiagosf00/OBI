#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int N, M, C, x;
    vector<int> c(101);
    vector<int> album(101, 0);

    cin >> N >> M >> C;
    for(int i=0;i<C;i++){
        cin >> c[i];
    }

    for(int i=0;i<M;i++){
        cin >> x;
        album[x]=1;
    }

    int resp = 0;
    for(int i=0;i<C;i++){
        if(album[c[i]]==0){
            resp++;
        }
    }

    cout << resp << endl;

    return 0;
}