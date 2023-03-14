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

using mint = modint1000000007;

int main(){
  int n,q;
  cin >> n >> q;
  vector<ll> x(q),y(q),z(q),w(q);
  REP(i,q){
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    x[i]--; y[i]--; z[i]--;
  }

  mint ans=1;
  REP(i, 60){
    int cnt=0;
    REP(j, (1<<n)){
      bool ok = true;
      REP(k,q){
        int xi = (j >> x[k])&1;
        int yi = (j >> y[k])&1;
        int zi = (j >> z[k])&1;

        int wi = (w[k] >> i)&1;

        if(wi==1 && ((xi || yi || zi) == 0))ok = false;
        if(wi==0 && ((xi || yi || zi) == 1))ok = false;
      }
      if(ok)cnt++;
    }
    //cout << i << " " << cnt << endl;
    ans *= cnt;
  }
  cout << ans.val() << endl;
}

