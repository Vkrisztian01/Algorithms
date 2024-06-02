#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
using ll = long long;
#define M 1000000007

ll fact[1000001];
ll q,a,b;

void f()
{
    fact[0]=1;
    for(int i=1;i<=1000001;i++) fact[i]=(i*fact[i-1])%M;
}

ll exp(ll a,ll b)
{
    ll bits[31];
    bits[0]=a;
    for(int i=1;i<=30;i++) bits[i]=(bits[i-1]*bits[i-1])%M;
    ll ans=1;
    for(int i=0;i<=30;i++)
    {
        if((b & (1<<i))!=0) ans=(ans*bits[i])%M;
    }
    return ans;
}

ll c(ll a,ll b)
{
    ll ans=fact[a];
    ans*=exp(fact[b],M-2);
    ans%=M;
    ans*=exp(fact[a-b],M-2);
    ans%=M;
    return ans;
}

int main()
{
    f();
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        cout<<c(a,b)<<"\n";
    }
    return 0;
}
