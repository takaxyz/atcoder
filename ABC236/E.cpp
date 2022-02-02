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

int n;
vi a;
double ans=0;
vector<ll> z;

ll ans2=-1;


bool f(double x){
  vector<double> b(n);
  REP(i,n){
    b[i] = (double)a[i] - x;
  }
  
  vector<double> dp(2,-1e18);
  dp[1]=0;
  // dp[0]: 選ばない、dp[1]: 選ぶ

  REP(i,n){
    vector<double> d(2,-1e18);
    swap(d,dp);
    // 選ぶ
    chmax(dp[1],d[1]+b[i]);
    chmax(dp[1],d[0]+b[i]);
    // 選ばない
    chmax(dp[0],d[1]);
  }
  return (dp[0]>=0 || dp[1] >= 0);
}


double solveAve(){
  double ok=0, ng=INF;

  REP(_,50){
    double mid = (ok+ng)/2;

    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  return ok;  
}

bool g(int x){
  vi b(n);
  REP(i,n){
    if(a[i] >= x)b[i]=1;
    else b[i]=-1;
  }
  
  vi dp(2,-10000000);
  dp[1]=0;
  // dp[0]: 選ばない、dp[1]: 選ぶ

  REP(i,n){
    vi d(2,-10000000);
    swap(d,dp);
    // 選ぶ
    chmax(dp[1],d[1]+b[i]);
    chmax(dp[1],d[0]+b[i]);
    // 選ばない
    chmax(dp[0],d[1]);
  }
  return (dp[0]>0 || dp[1] > 0);
}

int solveMid(){
  int ok=1, ng=INF;

  while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;

    if(g(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  return ok;  
}

int main(){
  cin >> n;
  a.resize(n);
  REP(i,n){
    cin >> a[i];
  }

  printf("%0.5f\n", solveAve());
  cout << solveMid() << endl;

}

