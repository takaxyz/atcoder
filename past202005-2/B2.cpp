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
//const int INF=(1<<29);

int main(){
  int N,M,Q;
  cin >> N >> M >> Q;

  VI score(M+1, N);
  vector<set<int>> st(M+1, set<int>());

  VI ans(N+1, 0);

  REP(i,Q){
    int s,n,m;
    cin >> s;
    if(s==1){
      cin >> n;
      cout << ans[n] << endl;
    }else{
      cin >> n >> m;
      score[m]--;
      ans[n] += score[m];

      for(auto v: st[m]){
        ans[v]--;
      }
      st[m].insert(n);
    }
  }
}


