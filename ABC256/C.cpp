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
  vi h(3), w(3);
  REP(i,3)cin >> h[i];
  REP(i,3)cin >> w[i];

  vvi p(3, vi(3));
  // i j
  // k l
  int ans=0;
  FOR(i,1,30)FOR(j,1,30)FOR(k,1,30)FOR(l,1,30){
    p[0][0]=i;
    p[0][1]=j;
    p[1][0]=k;
    p[1][1]=l;
    p[0][2]=h[0]-p[0][0]-p[0][1];
    if(p[0][2]<=0)continue;
    p[1][2]=h[1]-p[1][0]-p[1][1];
    if(p[1][2]<=0)continue;
    p[2][0]=w[0]-p[0][0]-p[1][0];
    if(p[2][0]<=0)continue;
    p[2][1]=w[1]-p[0][1]-p[1][1];
    if(p[2][1]<=0)continue;

    p[2][2]=h[2]-p[2][0]-p[2][1];
    if(p[2][2]<=0)continue;

    if(w[2] != p[0][2] + p[1][2]+ p[2][2])continue;
    ans++;
  }

  cout << ans << endl;
}

