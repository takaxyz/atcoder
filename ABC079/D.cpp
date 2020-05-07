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
  int H,W;
  cin >> H >> W;

  int c[10][10];
  REP(i,10)REP(j,10)cin >> c[i][j];

  REP(k,10)REP(i,10)REP(j,10){
    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  }

  int ans=0;
  REP(i,H)REP(j,W){
    int a;
    cin >> a;
    if(a==-1)continue;
    ans+=c[a][1];
  }
  cout << ans << endl;
}

