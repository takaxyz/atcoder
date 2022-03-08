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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  
  ll x = 0;
  set<int> st;
  vector<ll> b;
  int nx;
  for(ll i = 0; i < k; i++){
    nx = x % n;
    if(st.count(nx)!=0)break;
    st.insert(nx);
    x += a[nx];
    b.push_back(a[nx]);
  }


  ll ans = 0;
  REP(i,b.size()){
    ans += b[i];
    k--;
  }

  int j = 0;
  while(b[j] != a[nx])j++;
  ll sum = 0;
  FOR(i,j,b.size())sum += b[i];
  int len = b.size()-j;

  ans += (k / len) * sum;
  k -= (k/len) * len;
  while(k--){
    ans += b[j];
    j++;
  }

  cout << ans << endl;
}

