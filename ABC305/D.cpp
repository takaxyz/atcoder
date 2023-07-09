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
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];

  vi sum(n);
  REP(i,n-1){
    if(i%2==0){
      sum[i+1] = sum[i];
    }else{
      sum[i+1] = sum[i] + a[i+1] - a[i];
    }
  }
  //REP(i,n)cout << sum[i] << endl;


  auto f = [&](int x) -> int {
    int i = upper_bound(ALL(a), x) - a.begin();

    return sum[i-1] + (sum[i] - sum[i-1]) / (a[i]-a[i-1]) * (x - a[i-1]);
  };

  int q;
  cin >> q;
  REP(_,q){
    int l, r;
    cin >> l >> r;

    cout << f(r) - f(l) << endl;
  }
}

