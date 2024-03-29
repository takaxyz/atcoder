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

vi p;
vector<ll> c;

ll solve(int st, int k){
  ll sum=0;
  int v = st;
  int cnt=0;
  ll mx = -LINF;
  vector<ll> cc;

  while(true){
    sum += c[v];
    chmax(mx,sum);
    v = p[v];
    cc.push_back(c[v]);
    cnt++;
    if(v==st)break;
  }

  ll ret=0;

  if(k > cnt){
    ret = 0;
    if(sum > 0){
      ret += sum * ((k / cnt)-1);
      k -= ((k/cnt)-1) * cnt;
      ll tmp = ret;
      REP(i,k){
        tmp += cc[i%cc.size()];
        chmax(ret, tmp);
      }
    }else{
      ret = mx;  
    }
  }else{
    ll tmp = 0;
    ret = -LINF;
    REP(i,k){
      tmp += cc[i%cc.size()];
      chmax(ret, tmp);
    }
  }
  return ret;
}

int main(){
  int n, k;
  cin >> n >> k;
  p.resize(n);
  c.resize(n);
  REP(i,n){
    cin >> p[i];
    p[i]--;
  }
  REP(i,n)cin >> c[i];

  ll ans=-LINF;
  REP(i,n)chmax(ans, solve(i, k));
  cout << ans << endl;
}

