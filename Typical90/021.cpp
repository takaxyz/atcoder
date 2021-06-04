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

vvi edge,edge2;
int n,m;

vector<bool> visited;
vi ord;
void dfs(int v){
  visited[v]=true;

  for(auto x: edge[v]){
    if(visited[x])continue;
    dfs(x);
  }
  ord.push_back(v);
}

ll cnt;
void dfs2(int v){
  visited[v]=true;

  for(auto x: edge2[v]){
    if(visited[x])continue;
    dfs2(x);
  }
  cnt++;
}

int main(){
  cin >> n >> m;
  edge.resize(n); edge2.resize(n);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b); edge2[b].push_back(a);
  }

  visited.resize(n,false);
  REP(i,n){
    if(visited[i])continue;
    dfs(i);
  }

  // REP(i,n){
  //   cout << i << " " << num[i] << endl;
  // }

  REP(i,n)visited[i]=false;
  reverse(ALL(ord));
  ll ans=0;
  for(auto i: ord){
    // printf("%d\n",i);
    if(visited[i])continue;
    cnt=0;
    dfs2(i);
    ans += cnt * (cnt-1LL) / 2LL;
    // printf("%d %d %d\n",i, cnt, ans);
  }
  cout << ans << endl;
}

