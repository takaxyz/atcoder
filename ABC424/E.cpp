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

void solve(){
  int n,k,x;
  cin >> n >> k >> x;
  
  priority_queue<pair<double,ll>> q;
  REP(i,n){
    int a;
    cin >> a;
    q.push({a,1});
  }

  while(k){
    auto [v, cnt] = q.top(); q.pop();
    
    if(k < cnt){
      q.push({v, cnt-k});
      q.push({v/2, k*2});
      k = 0;
    }else{
      q.push({v/2, cnt*2});
      k -= cnt;
    }
  }

  while(q.size()){
    auto [v, cnt] = q.top(); q.pop();
    
    if(x <= cnt){
      printf("%.12f\n",v);
      return;
    }else x -= cnt;

  }


}


int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

