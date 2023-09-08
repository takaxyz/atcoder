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
  int n;
  cin >> n;
  vector<vector<ll>> d(n,vector<ll>(n));
  REP(i,n)FOR(j,i+1,n){
    cin >> d[i][j];
    d[j][i]=d[i][j];
  }

  vi used(n);
  ll sum=0;
  ll ans=0;
  auto dfs = [&](auto dfs) -> void{
    int c=0;
    REP(i,n)if(used[i]==0)c++;
    if(c <= 1){
      chmax(ans,sum);
      return;
    }


    int s=-1;
    REP(i,n)if(used[i]==0){
      s=i;
      break;
    }
    used[s]=1;
    REP(j,n){
      if(used[j]==0){
        used[j]=1;
        sum += d[s][j];
        dfs(dfs);
        used[j]=0;
        sum -= d[s][j];
      }
    }
    used[s]=0;
  };

  if(n%2==0){
    dfs(dfs);
  }else{
    REP(i,n){
      used[i]=1;
      dfs(dfs);
      used[i]=0;
    }
  }

  cout << ans << endl;
}

