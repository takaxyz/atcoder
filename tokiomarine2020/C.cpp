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
  int N, K;
  cin >> N >> K;

  vi a(N);

  REP(i,N)cin >> a[i];

  REP(i, K){
    vi s(N+1,0);
    REP(j,N){
      int l = max(j-a[j], 0);
      int r = min(j+a[j]+1, N);
      s[l]+=1;
      s[r]-=1;
    }
    a[0]=s[0];
    REP(j,N){
      s[j+1] = s[j] + s[j+1];
    }
    int mi = INF;
    REP(j,N){
      a[j] = s[j];
      chmin(mi, a[j]);
    }
    if(mi == N)break;
  }

  REP(i,N){
    cout << a[i] << (i==N-1 ? "\n" : " ");
  }
}

