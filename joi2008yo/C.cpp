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

int p[1001];

int main(){
  int n,m;
  cin >> n >> m;

  p[0]=0;
  REP(i,n){
    cin >> p[i+1];
  }

  VI pp;
  REP(i,n+1)FOR(j,i,n+1)pp.emplace_back(p[i]+p[j]);

  sort(ALL(pp));
  pp.erase(unique(ALL(pp)), pp.end());

  int ans = 0;
  REP(i,pp.size()){
    if(m-pp[i]<=0)continue;

    auto iter = upper_bound(ALL(pp), m - pp[i]);
    if(iter != pp.begin()){
      iter--;
      chmax(ans, *iter + pp[i]);
    }
  }
  cout << ans << endl;
}

