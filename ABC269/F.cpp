#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

using mint = modint998244353;

int n,m,q;

// even, even
mint sum4(int x,int y){
  if(x==0 || y == 0)return 0;

  mint xx = x;
  mint yy = y;

  mint s = m + 2;
  s += (xx - 1) * m + yy;
  s *= xx/2 * yy/2;
  s /= 2;
  return s;
}

// odd, odd
mint sum3(int x,int y){
  if(x==0 || y == 0)return 0;

  mint xx = x;
  mint yy = y;

  mint s = (xx - 1) * m + yy + 1;
  s *= ((xx + 1)/2) * ((yy+1)/2);
  s /= 2;
  return s;
}

mint sum2(int x, int y){
  if(x==0 || y == 0)return 0;

  if(x%2==1){
    return sum3(x,y);
  }else{
    return sum4(x,y);
  }
}

mint sum(int x, int y){
  if(x==0 || y == 0)return 0;

  mint ret=0;
  if((x+y)%2==0){
    ret += sum2(x,y);
    ret += sum2(x-1,y-1);
  }else{
    ret += sum2(x-1,y);
    ret += sum2(x,y-1);
  }
  return ret;
}


void solve(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  mint ans=0;
  ans += sum(b,d);
  a--;c--;
  ans -= sum(b,c);
  ans -= sum(a,d);
  ans += sum(a,c);
  cout << ans.val() << endl;
}

int main(){
  cin >> n >> m >> q;
  REP(i,q)solve();
}

