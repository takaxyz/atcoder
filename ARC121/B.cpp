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

ll f(vector<ll> x, vector<ll> y){
  ll ret=LINF;
  int i=0;
  int j=0;
  while(i < x.size() && j < y.size()){
    chmin(ret, abs(y[j]-x[i]));
    if(x[i]==y[j])return 0;
    else if(x[i]<y[j]){
      i++;
    }else{
      j++;
    }
  }
  return ret;
}

int main(){
  int n;
  cin >> n;
  vector<ll> r,g,b;

  REP(i,2*n){
    ll a;
    char c;
    cin >> a >> c;
    if(c=='R'){
      r.emplace_back(a);
    }else if(c=='G'){
      g.emplace_back(a);
    }else{
      b.emplace_back(a);
    }
  }

  if(r.size()%2==0 && g.size()%2==0){
    cout << 0 << endl;
    return 0;
  }
  sort(ALL(r));
  sort(ALL(g));
  sort(ALL(b));
  ll ans=LINF;

  ll rg = f(r,g);
  ll gb = f(g,b);
  ll br = f(b,r);
  if(r.size()%2==0){
    chmin(ans, gb);
    chmin(ans, rg+br);
  }else if(g.size()%2==0){
    chmin(ans, br);
    chmin(ans, rg+gb);
  }else{
    chmin(ans,rg);
    chmin(ans,gb+br);
  }
  cout << ans << endl;
}

