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
  int n,q;
  cin >> n >> q;

  vector<ll> s(n-1);

  vi t(q), x(q), y(q);
  vector<ll> v(q,-1);
  REP(i,q){
    cin >> t[i] >> x[i] >> y[i] >> v[i];
    x[i]--; y[i]--;
  }

  REP(i,q){
    if(t[i]==1)continue;
    s[x[i]] = v[i];
  }

  vector<ll> u(n,0);

  REP(i,n-1){
    if(s[i] != -1){
      u[i+1] = s[i] - u[i];
    }
  }

  // REP(i,n){
  //   cout << i << " " << u[i] << endl;
  // }

  dsu uf(n);
  REP(i,q){
    if(t[i]==0){
      uf.merge(x[i], y[i]);
    }else{
      if(uf.same(x[i],y[i])){
        if(x[i] % 2 == y[i] % 2) cout << u[y[i]] + v[i] - u[x[i]] << endl;
        else cout << u[y[i]] - v[i] + u[x[i]] << endl;
      }else{
        cout << "Ambiguous" << endl;
      }
    }
  }

}

