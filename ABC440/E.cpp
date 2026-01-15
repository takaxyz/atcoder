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
  int n,k,x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  sort(RALL(a));

  vi d(n);
  d[0] = k;

  priority_queue<pair<ll,vi>> q;

  auto push = [&](vi& d){
    ll sum = 0;
    REP(i,n)sum += a[i]*d[i];
    q.push({sum, d});
  };

  push(d);

  while(x--){
    auto [s, d] = q.top(); q.pop();
    cout << s << endl;

    int i = n -1;
    while(d[i]==0)i--;

    if(i < n -1){
      d[i]--; d[i+1]++;
      push(d);
      d[i]++; d[i+1]--;
    }

    if(i > 0 && d[i-1]>0){
      d[i-1]--; d[i]++;
      push(d);
    }
  }


}

