#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  ll ans=0;
  ll n;
  cin >> n;

  ans = n*(n+1)/2;
  ans -= (n/3)*(3+(n/3)*3)/2;
  ans -= (n/5)*(5+(n/5)*5)/2;
  ans += (n/15)*(15+(n/15)*15)/2;

  cout << ans << endl;
}

