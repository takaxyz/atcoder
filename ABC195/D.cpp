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

void solve(vector<P>& vw, vi& x){
  sort(ALL(x));


  int ans=0;
  for(auto& p : vw){
    int v = p.first;
    int w = p.second;

    REP(i,x.size()){
      if(x[i]>=w){
        ans += v;
        x.erase(x.begin() + i);
        break;
      }
    }
  }
  cout << ans << endl;
}


int main(){
  int n,m,q;
  cin >> n >> m >> q;

  vector<P> vw(n);
  REP(i,n){
    int a,b;
    cin >> a >> b;
    vw.emplace_back(b,a);
  }
  sort(ALL(vw));
  reverse(ALL(vw));

  vi x(m);
  REP(i,m)cin >> x[i];

  REP(i,q){
    int l,r;
    cin >> l >> r;

    vi xx;
    REP(j,l-1)xx.push_back(x[j]);
    FOR(j,r,m)xx.push_back(x[j]);
    solve(vw,xx);
  }

}

