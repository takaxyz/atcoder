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
  int n,q;
  cin >> n >> q;
  vector<ll> h(n);
  REP(i,n)cin >> h[i];

  // dif[0] = 奇数番目 - 偶数番目
  // dif[1] = 偶数番目 - 奇数番目
  vector<map<ll,int>> dif(2);
  REP(i,n-1){
    ll d = h[i+1]-h[i];
    dif[i%2][d]++;
  }

  vector<ll> D(2);

  REP(i,q){
    int t;
    cin >> t;
    if(t==3){
      int u;
      ll v;
      cin >> u >> v;
      u--;
      if(u>0){
        ll old = h[u] - h[u-1];
        dif[(u-1)%2][old]--;
        ll now = h[u] + v - h[u-1];
        dif[(u-1)%2][now]++;
      }
      if(u+1<n){
        ll old = h[u+1] - h[u];
        dif[u%2][old]--;
        ll now = h[u+1] - v - h[u];
        dif[u%2][now]++;
      }
      h[u] += v;
    }else{
      ll v;
      cin >> v;
      D[--t]+=v;
    }
    // cout << t << endl;
    // REP(i,2){
    //   for(auto &v: dif[i]){
    //     cout << v.first << " " << v.second << endl;
    //   }
    //   cout << endl;
    // }
    cout << dif[0][D[0]-D[1]] + dif[1][D[1]-D[0]] << endl;
  }

}

