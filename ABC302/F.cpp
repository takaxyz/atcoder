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
  int n, m;
  cin >> n >> m;
  vvi edge(n+m);
  REP(i,n){
    int v = i + m;
    int a;
    cin >> a;
    REP(_,a){
      int s;
      cin >> s;
      s--;
      edge[s].pb(v);
      edge[v].pb(s);
    }
  }

  queue<int> q;
  vi d(n+m,INF);
  q.push(0);
  d[0]=0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto nv : edge[v]){
      if(d[nv] != INF)continue;
      d[nv] = d[v]+1;
      q.push(nv);
    }
  }
  if(d[m-1]==INF){
    cout << -1 << endl;
  }else{
    cout << (d[m-1] - 2)/2  << endl;
  }

}

