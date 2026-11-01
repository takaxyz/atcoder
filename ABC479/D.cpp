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
  int n,q;
  cin >> n >> q;
  vector<ll> l(n-1),r(n-1);
  REP(i,n-1)cin >> l[i];
  REP(i,n-1)cin >> r[i];

  vector<ll> lmi(n,LINF),rmi(n,LINF);
  ll mi=LINF;
  for(int i = n-1; i>=0; i--){
    lmi[i] = mi;
    if(i>=1)chmin(mi, l[i-1]);
  }
  
  mi=LINF;
  for(int i = 0; i < n; i++){
    rmi[i] = mi;
    if(i < n-1)chmin(mi, r[i]);
  }

  REP(_,q){
    int s,t;
    cin >> s >> t;
    s--; t--;
    if(s == 0){
      cout << r[s] << endl;
    }else if(s == n-1){
      cout << l[s-1] << endl;
    }else{
      if(s < t){
        cout << min(l[s-1]+rmi[s], r[s]) << endl;

      }else{
        cout << min(l[s-1], r[s]+lmi[s]) << endl;
      }
    }
  }


  //for (auto x: lmi)cout << x << endl;
  //cout << endl;
  //for (auto x: rmi)cout << x << endl;
  


}

