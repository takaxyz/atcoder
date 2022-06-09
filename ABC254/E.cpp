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

int main(){
  int n,m;
  cin >> n >> m;
  vvi edge(n, vi());

  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  int q;
  cin >> q;
  vi d(n,-1);
  REP(_,q){
    int x, k;
    cin >> x >> k;
    x--;

    if(k==0){
      cout << x+1 << endl;
      continue;
    }
    queue<int> q;
    d[x]=0;
    q.push(x);
    vi vs;
    vs.push_back(x);
    while(q.size()){
      int v = q.front(); q.pop();

      for(auto nx: edge[v]){
        if(d[nx] != -1)continue;
        d[nx] = d[v] + 1;
        vs.push_back(nx);
        if(d[nx]==k)continue;
        q.push(nx);
      }
    }

    int ans=0;
    for(auto x: vs){
      //cout << "   " << x + 1 << endl;
      ans += x + 1;
      d[x] = -1;
    }
    cout << ans << endl;

  }
}

