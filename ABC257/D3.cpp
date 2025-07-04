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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vector<ll> x(n),y(n),p(n);
  REP(i,n)cin >> x[i] >> y[i] >> p[i];

  auto f = [&](ll s) -> bool {
    vvi edge(n,vi());
    REP(i,n)REP(j,n){
      if(p[i] * s >= abs(x[i]-x[j])+ abs(y[i] - y[j]))edge[i].pb(j);
    }

    REP(s,n){
      queue<int> q;
      vi visited(n);
      q.push(s);
      visited[s]=1;
      while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto nv: edge[v])if(visited[nv]==0){
          visited[nv]=1;
          q.push(nv);
        }
      }
      int cnt=0;
      for(auto v: visited)if(v==1)cnt++;
      if(cnt==n)return true;
    }

    return false;
  };


  ll ok=4000000000ll, ng=0;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  cout << ok << endl;



}

