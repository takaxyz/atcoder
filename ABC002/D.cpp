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

int d[12][12];

int main(){
  int n, m;
  cin >> n >> m;

  REP(i,m){
    int x,y;
    cin >> x >> y;
    x--;y--;
    d[x][y]=1;
    d[y][x]=1;
  }

  int ans=0;
  REP(i,(1<<n)){
    VI m;
    REP(j,n){
      if((1<<j)&i)m.emplace_back(j);
    }

    bool ok=true;
    REP(j,m.size())FOR(k,j+1,m.size()){
      if(!d[m[j]][m[k]]){
        ok=false;
        break;
      }
    }
    if(ok)chmax(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
}

