// Language: C++
// Problem Page: http://wcipeg.com/problem/cake

// This problem uses the Difference Array and the Prefix Sum Array

#include <iostream>
#include <cstdio>

using namespace std;

int i,ii,n,m,k,x1,x2,y1,y2,q,asd;
long long da[5005][5005];
unsigned long long ans;
int main(){
    //freopen("DATA.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for (i=0;i<k;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        da[y1][x1] += 1;
        da[y2+1][x2+1] += 1;
        da[y1][x2+1] -= 1;
        da[y2+1][x1] -= 1;
    }

    for (i=1;i<=m;i++){
        for (ii=1;ii<=n;ii++){
            da[i][ii] += da[i-1][ii] + da[i][ii-1] - da[i-1][ii-1];
        }
    }
    for (i=1;i<=m;i++){
        for (ii=1;ii<=n;ii++){
            da[i][ii] += da[i-1][ii] + da[i][ii-1] - da[i-1][ii-1];
        }
    }

    scanf("%d",&q);
    for (asd=0;asd<q;asd++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans = (long long)(da[y2][x2] - da[y1-1][x2]-da[y2][x1-1]+da[y1-1][x1-1]);
        cout<<ans<<endl;
    }
    return 0;
}
