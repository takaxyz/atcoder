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

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
 
int main(){
  int h,w,n;
  cin >> h >> w;
  n = min(h,w);

  vector<string> c(h);
  REP(i,h)cin >> c[i];

  auto ok = [&](int hi, int wi) -> bool{
    return hi >= 0 && hi < h && wi >= 0 && wi < w;
  };

  auto ck = [&](int hi, int wi, int d) -> bool {
    REP(i,4){
      int hii = hi + dx[i]*d;
      int wii = wi + dy[i]*d;
      if(!ok(hii, wii))return false;
      if(c[hii][wii]=='.')return false;
    }
    return true;
  };

  vi ans(n+1);
  REP(i,h)REP(j,w){
    if(c[i][j]=='.')continue;
    int d = 1;
    while(ck(i,j,d))d++;
    d--;
    ans[d]++;
  }
  REP(i,n)cout << ans[i+1] << endl;
}

