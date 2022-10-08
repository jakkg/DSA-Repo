#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod=1000000007;
ll a[1000001];
ll p[1000001];
void sieve(ll n){
    a[0]=a[1]=1;
    ll c=0;
    for(ll i=2;i*i<=n;i++){
        if(a[i]==0){
            for(ll j=i*i;j<=n;j+=i){
                a[j]=1;
            }
        }
    }
    for(ll i=0;i<=n;i++){
        if(a[i]==0)c++;
        if(a[c]==0)p[i]=1;
    }
    c=0;
    for(ll i=1;i<=n;i++){
        c+=p[i];
        p[i]=c;
    }
}
int main(){
    fast;
    ll t;
    cin>>t;
    sieve(1000000);
    while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<p[r]-p[l-1]<<"\n";
    }
    return 0;
}