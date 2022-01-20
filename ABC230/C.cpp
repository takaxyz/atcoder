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

ll n,a,b,p,q,r,s;

bool ck(ll i, ll j){
  ll k = i - a;

  if(j == k+b){
    if(max(1-a,1-b) <= k && k <= min(n-a,n-b)){
      return true;
    }
  }

  if(j == b-k){
    if(max(1-a, b-n) <= k && k <= min(n-a,b-1)){
      return true;
    }
  }
  return false;
}


int main(){

  cin >> n >> a >> b >> p >> q >> r >> s;

  for(ll i = p; i <= q; i++){
    for(ll j = r; j <= s; j++){
      cout << (ck(i,j) ? "#" : ".");
      cout << (j==s ? "\n" : "");
    }
  }
}

