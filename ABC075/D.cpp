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
  int N,K;
  cin >> N >> K;

  vector<int> x(N),y(N);
  vector<int> xaxis(N),yaxis(N);


  REP(i,N){
    cin >> x[i] >> y[i];
    xaxis[i] = x[i];
    yaxis[i] = y[i];
  }

  sort(ALL(xaxis));
  sort(ALL(yaxis));

  ll ans = INF;

  REP(xi,N)FOR(xj,xi+1,N)REP(yi,N)FOR(yj,yi+1,N){
    int lx,rx,ly,ry;
    lx=xaxis[xi]; rx=xaxis[xj];
    ly=yaxis[yi]; ry=yaxis[yj];

    int cnt=0;
      REP(i,N){
        if(lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry)cnt++;
      }
      if(cnt >= K){
        ans = min(ans, 1LL*(rx-lx)*(ry-ly));
      }
  }

  cout << ans << endl;

}

