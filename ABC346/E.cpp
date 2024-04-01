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
  ll h,w;
  int m;
  cin >> h >> w >> m;
  vi t(m),a(m),x(m);
  REP(i,m){
    cin >> t[m-i-1] >> a[m-i-1] >> x[m-i-1];
    a[m-i-1]--;
  }

  vi hh(h),ww(w);
  int ch=0,cw=0;
  vector<ll> col(200001);
  col[0]=h*w;

  REP(i,m){
    if(t[i]==1){
      if(hh[a[i]]==0){
        hh[a[i]]=1;
        ch++;
        int v = w - cw;
        col[0] -= v;
        col[x[i]] += v;

      }
    }else{
      if(ww[a[i]]==0){
        ww[a[i]]=1;
        cw++;
        int v = h - ch;
        col[0] -= v;
        col[x[i]] += v;
      }
    }
  }

  int c=0;
  REP(i,col.size()){
    if(col[i]!=0)c++;
  }
  cout << c << endl;

  REP(i,col.size()){
    if(col[i]==0)continue;
    cout << i << " " << col[i] << endl;
  }

}

