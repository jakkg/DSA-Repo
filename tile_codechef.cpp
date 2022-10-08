#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod=1000000007;
ll I[3][3],mat[3][3];
void mult(ll a[][3],ll b[][3],ll m){
    ll res[3][3];
    for(ll i=1;i<=2;i++){
        for(ll j=1;j<=2;j++){
            res[i][j]=0;
            for(ll k=1;k<=2;k++){
                res[i][j]+=(((a[i][k]%mod)*(b[k][j]%mod))%mod);
                res[i][j]=res[i][j]%mod;
            }
        }
    }
    for(ll i=1;i<=2;i++){
        for(ll j=1;j<=2;j++){
            a[i][j]=res[i][j];
        }
    }
}
int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        mat[1][1]=0;
        mat[1][2]=mat[2][1]=mat[2][2]=1;
        I[1][1]=I[2][2]=1;
        I[1][2]=I[2][1]=0;
        ll n;
        cin>>n;
        ll dp1=1,dp2=2;
        n--;
        while(n){
            if(n%2){
                mult(I,mat,2);
                n--;
            }
            else{
                mult(mat,mat,2);
                n/=2;
            }
        }
        ll ans=(dp1*I[1][1])%mod+(dp2*I[2][1])%mod;
        ans=ans%mod;
        cout<<ans<<endl;
    }
    return 0;
}