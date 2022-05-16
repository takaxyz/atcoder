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

vector<bool> Eratosthenes(int N) {
  vector<bool> isprime(N+1, true);

  isprime[0] = isprime[1] = false;
  for (int p = 2; p <= N; ++p) {
    if (!isprime[p]) continue;
    for (int q = p * 2; q <= N; q += p) {
      isprime[q] = false;
    }
  }
  return isprime;
}

long long f(long long p,long long q){
  double est=1;
  est=(q*q*q);
  est*=p;
  if(est>4e18){return 4e18;}
  return p*q*q*q;
}

int main(){
  ll n;
  cin >> n;
  vector<bool> isprime = Eratosthenes(1000000);
  int ans=0;
  vector<ll> ps;
  REP(i,1000001)if(isprime[i])ps.emplace_back(i);

  REP(i, ps.size()-1){
    FOR(j,i+1,ps.size()){
      if(f(ps[i],ps[j]) <= n){
        ans++;
      }else break;

    }
  }
  cout << ans << endl;

}

