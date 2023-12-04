#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int n,m;
  cin >> n >> m;

  vvi edge(n);
  map<P,P> mp;
  REP(i,m){
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
    mp[{a,b}] = {x,y};
    mp[{b,a}] = {-x,-y};
  }

  vector<ll> x(n, LINF),y(n, LINF);
  queue<int> q;
  q.push(0);
  x[0]=0; y[0]=0;
  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(auto nv: edge[v]){
      if(x[nv]!=LINF)continue;
      auto [dx,dy] = mp[{v,nv}];
      x[nv] = x[v] + dx;
      y[nv] = y[v] + dy;
      q.push(nv);
    }
  }

  REP(i,n){
    if(x[i]==LINF){
      cout << "undecidable" << endl;
    }else{
      cout << x[i] << " " << y[i] << endl;
    }
  }
}

