#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod=1000000007;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll power(ll a,ll n,ll p){
    ll res=1;
    while(n){
        if(n%2){
            res=((res%p)*(a%p))%p;
            n--;
        }
        else{
            a=((a%p)*(a%p))%p;
            n/=2;
        }
    }
    return res;
}
int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        if((b-a)==0){
            a=power(a,n,mod);
            b=power(b,n,mod);
            cout<<(a+b)%mod<<"\n";
            continue;
        }
        ll ans=1,num=abs(b-a);
        for(ll i=1;i*i<=num;i++){
            if(num%i==0){
                ll aa=power(a,n,i);
                ll bb=power(b,n,i);
                if((aa+bb)%i==0)ans=max(ans,i);
                aa=power(a,n,num/i);
                bb=power(b,n,num/i);
                if((aa+bb)%(num/i)==0)ans=max(ans,num/i);
            }
        }
        cout<<ans%mod<<"\n";
    }
    return 0;
}