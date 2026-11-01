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

  vector edge(n,vector<P>());

  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb({b,i+1});
    edge[b].pb({a,i+1});
  }

  queue<int> q;
  q.push(0);

  vi seq;
  vector<P> par(n,{-1,-1});
  seq.push_back(0);
  par[0]={-2,0};

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(auto [nv, i] : edge[v]){
      if(par[nv].first !=-1)continue;

      par[nv] = {v, i};
      seq.push_back(nv);
      q.push(nv);
    }
  }

  reverse(ALL(seq));

  vector<ll> x(n,0);
  vi sz(n,1);
  for(auto v: seq){
    for(auto [nv, i]: edge[v]){
      if(par[v].first == nv)continue;
      sz[v] += sz[nv]; 
    }

    if(2*sz[v] < n){
      x[0] += par[v].second;
      x[v] -= par[v].second;
    }else{
      x[v] += par[v].second;
    }
  }

  reverse(ALL(seq));

  for(auto v: seq){
    for(auto [nv, i]: edge[v]){
      if(par[v].first == nv)continue;
      x[nv] += x[v]; 
    }
  }

  for(auto val: x)cout << val << endl;

}

