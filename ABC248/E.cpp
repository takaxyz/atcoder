#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  REP(i,n)cin >> x[i] >> y[i];
  int ans=0;
  vector<vector<bool>> visited(n, vector<bool>(n));

  if(k==1){
    cout << "Infinity" << endl;
    return 0;
  }

  REP(i,n)FOR(j,i+1,n){
    if(visited[i][j])continue;
    vi vlist;
    vlist.emplace_back(i);
    vlist.emplace_back(j);
    int cnt=2;
    FOR(k,j+1,n){
      if((x[k]-x[i]) * (y[j]-y[i]) == (x[j]-x[i]) * (y[k]-y[i])){
        vlist.emplace_back(k);
        cnt++;
      }
    }
    REP(i,vlist.size())FOR(j,i+1,vlist.size())visited[vlist[i]][vlist[j]]=true;

    if(cnt>=k)ans++;
  }
  cout << ans << endl;
}

