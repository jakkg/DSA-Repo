#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod=1000000007;
const ll N=90000000;
bool a[N];
vector<int> prime;
void sieve(){
    a[0]=a[1]=true;;
    for(ll i=2;i*i<N;i++){
        if(!a[i]){
            for(ll j=i*i;j<N;j+=i){
                a[j]=true;
            }
        }
    }
    for(ll i=2;i<N;i++){
        if(!a[i]){
            prime.pb(i);
        }
    }
}
int main(){
    fast;
    ll t;
    cin>>t;
    sieve();
    while(t--){
        ll n;
        cin>>n;
        cout<<prime[n-1]<<"\n";
    }
    return 0;
}