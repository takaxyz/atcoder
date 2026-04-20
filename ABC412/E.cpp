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
  ll l,r;
  cin >> l >> r;
  l++;

  vi ps = eratosthenes(1e7);

  int ans=1;
  vi is_p(r-l+1);

  for(auto p: ps){
    for(ll i = (l + p - 1)/p * p; i <= r; i += p){
      if(is_p[i-l])continue;

      is_p[i-l]=1;
      ll j = i;
      while(j % p == 0)j/=p;

      if(j == 1)ans++;
    }
  }

  for(auto x: is_p)ans += x == 0;

  cout << ans << endl;
}

