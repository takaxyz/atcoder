#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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
  int N;
  cin >> N;
  
  int m = (1<<N);
  vvi t(N,vi());

  REP(i,m){
    int tt;
    cin >> tt;
    t[0].emplace_back(tt);
  }

  map<int,int> ans;
  REP(i,N-1){
    REP(j,(m>>i)/2){
      int x=2*j;
      int y=2*j+1;
      if(t[i][x] > t[i][y]){
        t[i+1].eb(t[i][x]);
        ans[t[i][x]] = i+1;
        ans[t[i][y]] = i;
      }else{
        t[i+1].eb(t[i][y]);
        ans[t[i][y]] = i+1;
        ans[t[i][x]] = i;
      }
    }
  }


  REP(i,m){
    PRINT(ans[t[0][i]]+1);
  }
}

