#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  vector<ll> a(N);
  REP(i,N)cin>>a[i];

  vector<ll> s(N+1);
  s[0]=0;
  REP(i,N)s[i+1]=s[i]+a[i];

  ll ans = INF;
  FOR(i,1,N){
    ans = min(ans, abs(2 * s[i] - s[N]));
  }
  cout << ans << endl;
}

