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
  int h,w;
  cin >> h >> w;
  vvi a(h,vi(w));
  vvi b(h,vi(w));

  REP(i,h)REP(j,w)cin >> a[i][j];
  REP(i,h)REP(j,w)cin >> b[i][j];

  vi hh(h), ww(w);
  REP(i,h)hh[i]=i;  
  REP(i,w)ww[i]=i;  

  int ans=INF;
  do{
    do{
      bool ok=true;
      REP(i,h)REP(j,w){
        if(a[i][j] != b[hh[i]][ww[j]]){
          ok=false;
        }
      }

      if(ok){
        int cnt=0;
        REP(i,h)FOR(j,i+1,h)if(hh[i]>hh[j])cnt++;
        REP(i,w)FOR(j,i+1,w)if(ww[i]>ww[j])cnt++;
        chmin(ans,cnt);
      }
    }while(next_permutation(ALL(ww)));
  }while(next_permutation(ALL(hh)));

  cout << (ans==INF ? -1 : ans) << endl;
}

