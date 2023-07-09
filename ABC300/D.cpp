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

  //cout << mx << endl;

  vi ps = eratosthenes(mx);
  int sz = ps.size();

  ll ans=0;
  int p = sz - 1; 
  REP(i, sz){
    ll x = ps[i]*ps[i];
    if(x>n)break;

    while(x * ps[p] * ps[p] > n)p--;

    int p2 = p;
    FOR(j, i+1, sz){
      x *= ps[j];
      if(x>n)break;

      while(x * ps[p2] * ps[p2] > n)p2--;
      if(p2 <= j)break;
      ans += (p2 - j);
      //cout << ps[i] << " " << ps[j] << " " << ps[p2] << endl;
      x /= ps[j];
    }
  }
  cout << ans << endl;
}

