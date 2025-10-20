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
  vvi edge(n);
  REP(_,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }

  auto calc = [&](int r){
    vi d(n,-1);
    queue<int> q;
    q.push(r);
    d[r]=0;
    while(q.size()){
      int v = q.front();
      q.pop();

      for(auto nv: edge[v]){
        if(d[nv]!=-1)continue;

        d[nv] = d[v] + 1;
        q.push(nv);
      }
    }
    return d;
  };

  auto d0 = calc(0);
  int x = n-1;
  for(int i = n-2; i >= 0; i--)if(d0[i] > d0[x])x = i;

  auto dx = calc(x);
  int y = n-1;
  for(int i = n-2; i >= 0; i--)if(dx[i] > dx[y])y = i;

  auto dy = calc(y);
  if(y > x){
    swap(dx,dy);
    swap(x,y);
  }

  REP(i,n){
    cout << (dx[i] >= dy[i] ? x + 1 : y +1) << endl;
  }


}

