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
  string x,y;
  cin >> x >> y;

  const ll MX = 1e18;
  vector<vector<ll>> cnt;
  vector<ll> len;


  cnt.pb(vector<ll>(26));
  for(auto c: x){
    cnt.back()[c - 'a']++;
  }
  len.pb(x.size());

  cnt.pb(vector<ll>(26));
  for(auto c: y){
    cnt.back()[c - 'a']++;
  }
  len.pb(y.size());

  while(true){
    int sz = len.size();
    if(len[sz-1]  > MX - len[sz-2])break;

    len.pb(len[sz-1] + len[sz-2]);
    cnt.pb(vector<ll>(26));
    REP(i,26)cnt[sz][i] = cnt[sz-1][i] + cnt[sz-2][i];
  }

  string z = y + x;
  vvi csum(z.size()+1,vi(26));
  REP(i,z.size()){
    REP(j,26){
      csum[i+1][j] = csum[i][j];
    }
    csum[i+1][z[i]-'a'] = csum[i][z[i]-'a']+1;
  }  

  //REP(i,z.size()+1)REP(j,26)printf("%d %d %d\n",i,j,csum[i][j]);


  auto f = [&](ll r, char c, auto f) -> ll {
    //if(r == 0)return 0;

    if(len[2] >= r){
      //cout << csum[r][c-'a'] << endl;
      return csum[r][c-'a'];
    }

    int i = 2;
    while(i < (int)len.size() && len[i] <= r)i++;
    i--;
    //cout << "  " << i << " " << cnt[i][c-'a']  << endl;
    return cnt[i][c-'a'] + f(r-len[i], c, f);
  };
  
  int q;
  cin >> q;
  REP(_,q){
    ll l,r;
    char c;
    cin >> l >> r >> c;
    l--;
    cout << f(r,c,f) - f(l,c,f) << endl;
  }






}

