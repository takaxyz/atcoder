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

const int MAX = 1000005;

int main(){
  int n;
  cin >> n;
  vi a(n);
  vi cnt(MAX), sum(MAX+1);
  REP(i,n){
    cin >> a[i];
    cnt[a[i]]++;
  }

  REP(i,MAX)sum[i+1] += sum[i] + cnt[i];


  ll ans=0;
  REP(i,n){
    for(int j = 1; (j+1) * a[i] < MAX; j++){
      int l = j * a[i];
      int r = min((j+1) * a[i], MAX);

      if(j==1){
        ans += (ll)j * (sum[r]-sum[l] - 1);
      }else{
        ans += (ll)j * (sum[r]-sum[l]);
      }
      // if(sum[r]-sum[l]){
      //   cout << a[i] << " " << l << " " << r << " " << sum[r]-sum[l] << endl;
      //   cout << ans << endl;
      // }

    }
  }
  REP(i,MAX)ans -= (ll)cnt[i] * (cnt[i] - 1) / 2;

  cout << ans << endl;


}

