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

int n,q;
vvi edge;
vi x;
vvi s;

void dfs(int v, int p=-1){
  s[v].emplace_back(x[v]);

  for(auto w: edge[v]){
    if(w==p)continue;
    dfs(w,v);
    for(auto vv: s[w]){
      s[v].emplace_back(vv);
    }

  }
  sort(ALL(s[v]));
  reverse(ALL(s[v]));

  while(s[v].size() > 20){
    s[v].pop_back();
  }
}

int main(){
  cin >> n >> q;
  edge.resize(n);
  x.resize(n);
  s.resize(n);

  REP(i,n)cin >> x[i];

  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  dfs(0);

  // REP(i,n){
  //   REP(j,s[i].size()){
  //     cout << s[i][j] << (j==s[i].size()-1 ? "\n" : " ");
  //   }
  // }
  REP(i,q){
    int v,k;
    cin >> v >> k;
    v--;
    cout << s[v][k-1] << endl;
  }
}

