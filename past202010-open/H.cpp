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
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> s(n,vector<int>(m));
  REP(i,n)REP(j,m){
    char c;
    cin >> c;
    s[i][j] = c - '0';
  }

  int ans=0;
  REP(i,n)REP(j,m){
    FOR(t, 1, min(n+1,m+1)){
      if(i+t >= n+1 || j+t >=m+1)continue;

      vector<int> cnt(10,0);
      REP(x,t)REP(y,t){
        cnt[s[i+x][j+y]]++;
      }

      int mx = 0;
      REP(x,10)chmax(mx,cnt[x]);
      if(t*t-mx<= k){
        // REP(x,10){
        //   cout << cnt[x] << " ";
        // }
        // cout << endl;
        // cout << i << " " << j << " " << t << endl;
        chmax(ans,t);
      }
    }
  }
  cout << ans << endl;
}

