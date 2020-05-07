#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  ll a,b,n;
  cin >> a >> b >> n;
  // REP(i,n+1){
  //   cout << i << " " << a*i/b << " " << a*(i/b) << endl;
  // }

  ll ans = 0;
  if(n%b == 0){
    ans = a*(n-1)/b - a*((n-1)/b);
  }else{
    ll nn = (n/b)*b-1;
    ans = a*(n)/b - a*((n)/b);
    chmax(ans, a*(nn)/b - a*((nn)/b));
  }
  cout << ans << endl;

}

