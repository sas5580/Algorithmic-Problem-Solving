// Language: C++
// Problem Page: http://wcipeg.com/problem/ccc09s5

// The data structure used in this problem is the Difference Array

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int m,n,k,x,y,r,b,i,ii,l,ri,c,top,bot,tmp,best = 0;
int da[30005][1005];

int main(){
    scanf("%d%d%d",&m,&n,&k);
    for (int asdf=0;asdf<k;asdf++){
        scanf("%d%d%d%d",&x,&y,&r,&b);
        x-=1;y-=1;
        top = max(0,y-r);
        bot = min(y+r,m-1);
        for (i=top;i<=bot;i++){
            tmp = sqrt(r*r-(y-i)*(y-i));
            l = max(0,x-tmp);
            ri = min(n-1,x+tmp);
            da[i][l] += b;
            da[i][ri+1] -= b;
        }
    }

    for (i=0;i<m;i++){
        for (ii=0;ii<n;ii++){
            da[i][ii] += da[i][ii-1];
            if (da[i][ii] >best){
                best = da[i][ii];
                c = 1;
            }
            else if (da[i][ii] == best){
                c+=1;
            }
        }
    }
    cout<<best<<endl<<c;    

    return 0;
}
