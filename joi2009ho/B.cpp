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
  int d,n,m;
  cin >> d >> n >> m;
  VI s(n+1);
  s[0] = 0;
  REP(i,n-1)cin >> s[i+1];
  s[n] = d;
  sort(ALL(s));

  int ans=0;
  REP(i,m){
    int k;
    cin >> k;

    auto iter = lower_bound(ALL(s), k);

    if(*iter != k)ans += min(k - *(iter-1), *iter - k);

  }
  cout << ans << endl;

}


