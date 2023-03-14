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
  int n,p,k;
  cin >> n >> p >> k;
  vector<vector<ll>> a(n,vector<ll>(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  auto check = [&](ll x, int kk){
    vector<vector<ll>> d(n,vector<ll>(n));

    REP(i,n)REP(j,n)d[i][j] = (a[i][j]==-1 ? x : a[i][j]);

    REP(k,n)REP(i,n)REP(j,n){
      chmin(d[i][j], d[i][k]+d[k][j]);
    }

    int cnt=0;
    REP(i,n)REP(j,i){
      if(d[i][j]<=p)cnt++;
    }
    //cout << cnt << " " << kk << endl;
    return cnt <= kk;
  };


  auto f = [&](int kk){
    ll ok=LINF, ng=0;


    while(abs(ok-ng)>1){
      ll mid = (ok+ng)/2;
      //cout << ng << " " << ok << " " << mid << endl;
      if(check(mid,kk)){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    return ok;
  };

  ll l = f(k);
  ll r = f(k-1);

  if(l != LINF && r == LINF){
    cout << "Infinity" << endl;
  }else{
    cout << r - l << endl;
  }


}

