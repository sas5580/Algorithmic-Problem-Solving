// Language: C++
// Problem Page: http://wcipeg.com/problem/ioi1102

// This problem demonstrates the simplest use of the Prefix Sum Array

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int i,n,k,t[1000000],th,ans;
    cin>>n>>k;
    cin>>th;
    t[0] = th;    
    for (i=1;i<n;i++){
        cin>>th;
        t[i] = t[i-1]+th;        
    }
    ans = t[k-1];
    for (i=k;i<n;i++){
        ans = max(t[i]-t[i-k],ans);
    }
    cout<<ans;
    return 0;
}
