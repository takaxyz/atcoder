#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N,K;
  cin >> N >> K;
  ll ans = 0;

  if(K==0){
    cout << (ll)N*N << endl;
    exit(0);
  }

  FOR(i,K+1,N+1){
    int t = (i-K) * (N/i) + max(0,(N%i-K+1));
    ans += t;
  }
  cout << ans << endl;
}

