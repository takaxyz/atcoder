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

double memo[301][301][301];

int N;
double dp(int a,int b,int c){
  if(memo[a][b][c]>=0)return memo[a][b][c];
  if(a+b+c==0)return memo[a][b][c]=0.0;

  double res = 0.0;

  if(a>0)res += dp(a-1,b+1,c)*a;
  if(b>0)res += dp(a,b-1,c+1)*b;
  if(c>0)res += dp(a,b,c-1)*c;
  res += N;
  res /= (a+b+c);
  return memo[a][b][c]=res;
}

int main(){
  cin >> N;

  map<int,int> mp;
  REP(i,N){
    int a;
    cin >> a;
    mp[a]++;
  }

  memset(memo, -1, sizeof(memo));

  cout << fixed << setprecision(10) << dp(mp[3], mp[2], mp[1]) << endl;
}

