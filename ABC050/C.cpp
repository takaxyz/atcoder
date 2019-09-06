#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;

ll mod_pow(ll x,ll n, ll mod){
  if(n==0) return 1;
  ll res = mod_pow(x*x%mod, n/2, mod);
 
  if(n&1) res = res*x%mod;

  return res;
}

int main(){
  int N;
  cin >> N;

  map<int, int> m;

  REP(i,N){
    int a;
    cin >> a;
    m[a]++;
  }

  if(N&1){
    for(int i = 0; i < N; i+=2){
      if(i==0){
        if(m[i]!=1){
          cout << 0 << endl;
          return 0;
        }
      }else{
        if(m[i]!=2){
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }else{
    for(int i = 1; i < N; i+=2){
      if(m[i]!=2){
        cout << 0 << endl;
        return 0;
      }
    }
  }

  cout << mod_pow(2, N/2, MOD) << endl;
}

