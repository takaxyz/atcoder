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
vi c;
vvi edge;
vi ans;

void dfs(int v, int p, map<int,int> &mp){
  //cout << v << " " << p << endl;
  if(mp[c[v]]==0)ans.push_back(v);
  mp[c[v]]++;
  for(auto c: edge[v]){
    if(c==p)continue;

    dfs(c, v, mp);
  }
  mp[c[v]]--;
}

int main(){
  cin >> n;
  c.resize(n);
  edge.resize(n,vi());

  REP(i,n)cin >> c[i];
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  map<int, int> mp;
  dfs(0,-1,mp);

  sort(ALL(ans));
  REP(i,ans.size()){
    cout << ans[i] + 1 << endl;
  }
}

