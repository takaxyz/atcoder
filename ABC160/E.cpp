#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int x,y,a,b,c;

  cin >> x >> y >> a >> b>>c;
  vector<ll> p(a),q(b),r(c);
  vector<ll> sp(x+1,0), sq(y+1,0), sr(c+1,0);

  REP(i,a)cin >> p[i];
  REP(i,b)cin >> q[i];
  REP(i,c)cin >> r[i];

  sort(ALL(p));
  reverse(ALL(p));
  sort(ALL(q));
  reverse(ALL(q));
  sort(ALL(r));
  reverse(ALL(r));

  REP(i,x){
    sp[i+1] = sp[i]+p[i];
  }
  REP(i,y){
    sq[i+1] = sq[i]+q[i];
  }
  REP(i,c){
    sr[i+1] = sr[i]+r[i];
  }

  vector<ll> nn;
  REP(i,x)nn.push_back(p[i]);
  REP(i,y)nn.push_back(q[i]);
  REP(i,c)nn.push_back(r[i]);

  sort(ALL(nn));
  reverse(ALL(nn));

  ll ans=0;
  REP(i,x+y)ans+=nn[i];

  cout << ans << endl;

}

