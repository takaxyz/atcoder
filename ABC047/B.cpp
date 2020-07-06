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
  int W,H,N;
  cin >> W >> H >> N;
  vector<vector<int>> m(W, vector<int>(H,1));

  REP(i,N){
    int x, y, a;
    cin >> x >> y >> a;

    if(a==1){
      REP(j,x)REP(k,H)m[j][k]=0;
    }else if(a==2){
      FOR(j,x,W)REP(k,H)m[j][k]=0;
    }else if(a==3){
      REP(j,W)REP(k,y)m[j][k]=0;
    }else{
      REP(j,W)FOR(k,y,H)m[j][k]=0;
    }
  }

  int ans=0;
  REP(i,W)REP(j,H)ans+=m[i][j];

  cout << ans << endl;
}

