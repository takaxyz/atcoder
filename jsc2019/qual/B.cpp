#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  ll N, K;
  cin >> N >> K;

  int a[2005];
  REP(i,N)cin >> a[i];

  ll t = 0;
  REP(i,N)FOR(j,i+1,N){
    if(a[i] > a[j])t+=1;
  }
  ll s = 0;
  REP(i,N)REP(j,N){
    if(a[i] > a[j])s+=1;
  }
  t %= MOD;
  s %= MOD;


  cout << ((t * K) % MOD +  (((K * (K-1) / 2) % MOD) * s )) % MOD << endl;

}

