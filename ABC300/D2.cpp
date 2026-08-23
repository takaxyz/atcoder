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

vector<int> eratosthenes(const int n){
  vector<bool> is_prime(n+1,true);

  vector<int> p;

  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      for(int j=2; j*i<=n; j++){
        is_prime[i*j]=false;
      }
      p.emplace_back(i);
    }
  }

  return p;
}


int main(){
  ll n;
  cin >> n;

  ll mx = 1;
  while(mx * mx <= n)mx++;
  
  vi vs = eratosthenes(mx);

  int sz = vs.size();
  int pos = sz - 1;
  int ans = 0;
  REP(i,sz){
    ll x = (ll)vs[i] * vs[i];

    //cout << x << endl;
    while(x * vs[pos]*vs[pos] > n)pos--;

    int pos2 = pos;
    FOR(j,i+1,pos){
      x *= vs[j];

      while(x * vs[pos2] * vs[pos2] > n)pos2--;
      if(pos2 <= j)break;
      ans += pos2-j;

      x /= vs[j];
    }
  }
  cout << ans << endl;

}
