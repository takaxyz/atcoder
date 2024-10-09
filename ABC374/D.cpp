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

using mint = modint1000000007;
// using mint = modint998244353;

double calc(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); 
}

int main(){
  int n;
  double s,t;
  cin >> n >> s >> t;

  vi a(n),b(n),c(n),d(n);
  double lsum = 0;
  REP(i,n){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    lsum += calc(a[i],b[i],c[i],d[i])/ t;
  }

  vi ord(n);
  REP(i,n)ord[i]=i;

  vi aa(n),bb(n),cc(n),dd(n);
  double ans = 1e10;
  do{
    REP(k, (1<<n)){
      REP(j,n){
        if(k>>j & 1){
          aa[j]=a[ord[j]];
          bb[j]=b[ord[j]];
          cc[j]=c[ord[j]];
          dd[j]=d[ord[j]];
        }else{
          aa[j]=c[ord[j]];
          bb[j]=d[ord[j]];
          cc[j]=a[ord[j]];
          dd[j]=b[ord[j]];
        }
      }
      double msum = calc(0,0,aa[0],bb[0]) / s;

      REP(i,n-1){
        msum +=  calc(cc[i],dd[i],aa[i+1],bb[i+1]) / s;
      }
      chmin(ans, msum+lsum);
    }
  }while(next_permutation(ALL(ord)));
  printf("%.10f\n",ans);
}

