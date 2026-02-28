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
  int m,a,b;
  cin >> m >> a >> b;

  vector edge(m*m, vi());

  REP(i,m)REP(j,m){

    int k = (i * b + j * a) % m;

    edge[j*m + k].pb(i*m + j);
  }

  queue<int> q;
  vi visited(m*m);
  REP(i,m)REP(j,m){
    if(i == 0 || j == 0){
      q.push(i*m+j);
      visited[i*m+j]=1;
    }
  }

  while(q.size()){
    int v = q.front();
    q.pop();

    for(auto nv: edge[v]){
      if(visited[nv])continue;

      q.push(nv);
      visited[nv] = 1;
    }
  }

  int ans=0;
  REP(i,m*m)if(visited[i]==0)ans++;
  cout << ans << endl;

}

