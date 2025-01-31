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
  ll x, y;
  cin >> n >> m >> x >> y;

  map<ll, set<ll>> mpx, mpy;

  REP(_,n){
    ll x,y;
    cin >> x >> y;
    mpx[x].insert(y);
    mpy[y].insert(x);
  }
  int ans=0;
  REP(_,m){
    char d;
    ll c;
    cin >> d >> c;
    if(d=='U'){
      ll ny = y + c;
      auto it = mpx[x].lower_bound(y);
      while(it != mpx[x].end() && *it <= ny){
        ans++;
        //printf("erase %d %d\n", x, *it);
        mpy[*it].erase(x);
        it = mpx[x].erase(it);
      }
      y = ny;
    }else if(d=='D'){
      ll ny = y - c;
      auto it = mpx[x].lower_bound(ny);
      while(it != mpx[x].end() && *it <= y){
        ans++;
        //printf("erase %d %d\n", x, *it);
        mpy[*it].erase(x);
        it = mpx[x].erase(it);
      }
      y = ny;
    }else if(d=='L'){
      ll nx = x - c;
      auto it = mpy[y].lower_bound(nx);
      while(it != mpy[y].end() && *it <= x){
        ans++;
        //printf("erase %d %d\n", *it, y);
        mpx[*it].erase(y);
        it = mpy[y].erase(it);
      }
      x = nx;
    }else{
      ll nx = x + c;
      auto it = mpy[y].lower_bound(x);
      while(it != mpy[y].end() && *it <= nx){
        ans++;
        //printf("erase %d %d\n", *it, y);
        mpx[*it].erase(y);
        it = mpy[y].erase(it);
      }
      x = nx;
    }
  }
  cout << x << " " <<  y << " " << ans << endl;

}

