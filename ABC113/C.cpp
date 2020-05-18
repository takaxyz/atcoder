#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<P>> c(n+1);
  vector<int> ans1(m+1), ans2(m+1);

  REP(i,m){
    int p,y;
    cin >> p >> y;
    c[p].emplace_back(make_pair(y, i+1));
    ans1[i+1] = p;
  }


  FOR(i,1,n+1){
    sort(ALL(c[i]));
    REP(j, c[i].size()){
      ans2[c[i][j].second] = j+1;
    }
  }
  FOR(i,1,m+1){
    printf("%06d%06d\n",ans1[i], ans2[i]);
  }

}

