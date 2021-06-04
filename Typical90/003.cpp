#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

int n;
vvi edge;
vi depth;

void dfs(int v, int p, int d){
  for(auto x: edge[v]){
    if(x==p)continue;
    depth[x] = d+1;
    dfs(x, v, d+1);
  }
}

int main(){
  cin >> n;
  edge.resize(n);
  depth.resize(n);
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  depth[0] = 0;
  dfs(0, -1, 0);
  int mx = 0;
  int x;
  REP(i,n){
    if(mx < depth[i]){
      mx = depth[i];
      x = i;
    }
  }
  dfs(x,-1,0);
  mx = 0;
  REP(i,n){
    if(mx < depth[i]){
      mx = depth[i];
    }
  }

  cout << mx + 1 << endl;

}

