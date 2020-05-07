#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);

struct pos{
  int x;
  int y;
};

int main(){
  int H,W,D;
  cin >> H >> W >> D;

  vector<pos> p(H*W+1);

  REP(i,H)REP(j,W){
    int a;
    cin >> a;
    p[a] = pos{i,j};
  }

  vector<int> d(H*W+1,0);
  
  FOR(i,D+1,H*W+1){
    d[i] = d[i-D] + abs(p[i].x - p[i-D].x) + abs(p[i].y - p[i-D].y);
  }

  int Q;
  cin >> Q;
  REP(i,Q){
    int l,r;
    cin >> l >> r;
    cout << d[r] - d[l] << endl;
  }

}

