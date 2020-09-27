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

int main(){
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h)cin>>s[i];

  vi hh;
  REP(i,h)REP(j,w){
    if(s[i][j]=='#'){
      hh.emplace_back(i);
      break;
    }
  }
  hh.emplace_back(h);
  // REP(i,hh.size()){
  //   cout << hh[i] << endl;
  // }

  vector<vector<int>> ans(h, vector<int>(w));

  int cnt=0;
  REP(i,hh.size()-1){
    int x = hh[i];
    int y = hh[i+1];
    int now=0;
    cnt++;
    REP(j,w){
      if(s[x][j]=='#' && now++){
        cnt++;
        now++;
      }
      if(i==0){
        FOR(k,0,x)ans[k][j]=cnt;
      }
      FOR(k,x,y)ans[k][j]=cnt;
    }
  }

  REP(i,h)REP(j,w){
    cout << ans[i][j];
    cout << (j==w-1 ? "\n" : " ");
  }
}

