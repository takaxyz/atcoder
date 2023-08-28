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
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vvi edge(n1+n2);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);  
  }

  vi dist(n1+n2,-1);

  auto bfs = [&](int s) -> void{
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto nv: edge[v]){
        if(dist[nv]!=-1)continue;
        dist[nv] = dist[v]+1;
        q.push(nv);
      }
    }
  };

  bfs(0);
  int mx1=-1;
  REP(i,n1)chmax(mx1,dist[i]);

  int mx2=-1;
  bfs(n1+n2-1);
  FOR(i,n1,n1+n2)chmax(mx2,dist[i]);

  cout << mx1+mx2+1 << endl;
}

