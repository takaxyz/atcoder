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
  int n,m;
  cin >> n >> m;
  vi a,b,c;
  REP(_,n){
    int t,x;
    cin >> t >> x;
    if(t==0){
      a.pb(x);
    }else if(t==1){
      b.pb(x);
    }else{
      c.pb(x);
    }
  }

  sort(RALL(a));
  sort(RALL(b));
  sort(RALL(c));

  vector<ll> sa(a.size()+1);
  vector<ll> sb(b.size()+1);
  vector<ll> sc(c.size()+1);
  REP(i,a.size())sa[i+1] = sa[i]+a[i];
  REP(i,b.size())sb[i+1] = sb[i]+b[i];
  REP(i,c.size())sc[i+1] = sc[i]+c[i];

  ll ans=0;
  int j = 0;
  for(int i = 0; i < sb.size(); i++){
    ll sum = sb[i];

    while(j < sc.size() && sc[j]<i)j++;
    if(j==sc.size())break;
    if(i+j>m)break;
    sum += sa[min(m-i-j, (int)sa.size()-1)];
    chmax(ans,sum);
  }

  cout << ans << endl;

}

