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

int n;
vector<tuple<ll,ll,ll>> jp;


bool f(ll x){

  vector<vector<ll>> dist(n, vector<ll>(n,LINF));

  REP(i,n)REP(j,n){
    if(i==j){
      dist[i][j]=0;
      continue;
    }
    ll x1 = get<0>(jp[i]);
    ll y1 = get<1>(jp[i]);
    ll x2 = get<0>(jp[j]);
    ll y2 = get<1>(jp[j]);
    ll p1 = get<2>(jp[i]);

    if(p1*x >= abs(x1-x2)+abs(y1-y2)){
      dist[i][j]=1;
    }
  }

  REP(k,n)REP(i,n)REP(j,n){
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }

  REP(i,n){
    bool ok = true;
    REP(j,n){
      if(dist[i][j]==LINF)ok=false;
    }
    if(ok)return ok;
  }

  REP(j,n){
    bool ok = true;
    REP(i,n){
      if(dist[i][j]==LINF)ok=false;
    }
    if(ok)return ok;
  }
  return false;
}

int main(){
  cin >> n;

  REP(i,n){
    ll x,y,p;
    cin >> x >> y >> p;
    jp.emplace_back(x,y,p);
  }

  ll ok=4000000000ll, ng=0;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout << ok << endl;

}

