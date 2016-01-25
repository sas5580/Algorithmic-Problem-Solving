// Language: C++
// Problem Page: http://wcipeg.com/problem/ccc14s4

// The data structure used here is the Difference Array with coordinate compression

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>

using namespace std;

int i,ii,n,t,a,b,c,d,e;
long long ans=0;
int j,k;
int thngs[1000][5];
set <int> xs;
set <int> ys;
map <int,int> xc;
map <int,int> yc;
long long da[2005][2005];

int main(){
    //freopen("DATA.txt","r",stdin);
    scanf("%d%d",&n,&t);
    for (i=0;i<n;i++){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        thngs[i][0]=a;thngs[i][1]=b;thngs[i][2]=c;thngs[i][3]=d;thngs[i][4]=e;
        xs.insert(a);xs.insert(c);
        ys.insert(b);ys.insert(d);
    }
    vector <int> xv (xs.begin(),xs.end());
    vector <int> yv (ys.begin(),ys.end());
    for (i=0;i<xv.size();i++){
        xc[xv[i]] = i+1;
    }
    for (i=0;i<yv.size();i++){
        yc[yv[i]] = i+1;
    }

    for (i=0;i<n;i++){
        int x1=xc[thngs[i][0]],y1=yc[thngs[i][1]],x2=xc[thngs[i][2]],y2=yc[thngs[i][3]];
        da[y1][x1]+=thngs[i][4];
        da[y2][x2]+=thngs[i][4];
        da[y1][x2]-=thngs[i][4];
        da[y2][x1]-=thngs[i][4];
    }
    
    for (i=1;i<yc.size();i++){
        for (ii=1;ii<xc.size();ii++){
            da[i][ii] += da[i-1][ii]+da[i][ii-1]-da[i-1][ii-1];
            if (da[i][ii]>=t){
                ans += (long long)(yv[i]-yv[i-1])*(xv[ii]-xv[ii-1]);
            }
        }
    }
    cout<<ans;

    return 0;
}
