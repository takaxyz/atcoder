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
  int n,a,b,c;
  cin >> n >> a >> b >> c;

  VI l(n);
  REP(i,n)cin >> l[i];

  int ans=(1<<30);
  REP(i,(1<<(2*n))){
    VI cnt(3,0);
    VI sum(3,0);

    REP(j,n){
      int k = ((i>>(2*j)) & 3);
      cnt[k]++;
      sum[k]+=l[j];
    }

    if(cnt[0]==0 || cnt[1]==0 || cnt[2] ==0)continue;

    int mp= abs(a-sum[0]) + (cnt[0]-1)*10 + abs(b-sum[1]) + (cnt[1]-1)*10 +abs(c-sum[2]) + (cnt[2]-1)*10;
    chmin(ans, mp);
  }

  cout << ans << endl;


}

