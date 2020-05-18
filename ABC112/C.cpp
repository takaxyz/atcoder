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
  int n;
  cin >> n;
  VI x(n),y(n),h(n);
  int xx,yy,hh;
  REP(i,n){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i]>=1){
      xx = x[i];
      yy = y[i];
      hh = h[i];
    }
  }

  REP(cx,101)REP(cy,101){
    bool ok=true;
    int H = hh + abs(cx-xx) + abs(cy-yy);
    REP(i,n){
      if(h[i]!=max(H-abs(cx-x[i])-abs(cy-y[i]), 0)){
        ok=false;
        break;
      }
    }
    if(ok){
      cout << cx << " " << cy << " " << H << endl;
      return 0;
    }
  }
}

