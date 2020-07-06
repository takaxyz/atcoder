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
  int n,q;
  cin >> n >> q;
  vi x(n), r(n), h(n);
  vector<double> v(n);

  REP(i,n){
    cin >> x[i] >> r[i] >> h[i];
    v[i] = M_PI * r[i] * r[i] * h[i] / 3;
  }

  REP(i,q){
    int a,b;
    cin >> a >> b;

    double ans=0;
    REP(j,n){
      int bot = x[j];
      int top = x[j]+h[j];

      if(top <= a || b <= bot)continue;



      if(a <= bot && top <= b){
        ans += v[j];
      }else if(bot <= a && a<= top && top <= b){
        double rat = (double)(top-a) / (double)h[j];
        ans += v[j] * rat * rat * rat; 
      }else if(a <= bot && bot <= b && b<= top){
        double rat = (double)(top-b) / (double)h[j];
//        printf("%d %d %d %d %d\n", a,b,top, bot, h[j]);
        ans += v[j] * (1 - rat * rat * rat); 
      }else{
        double rat1 = (double)(top-b) / (double)h[j];
        double rat2 = (double)(top-a) / (double)h[j];

        ans += v[j] * (rat2 * rat2 * rat2- rat1*rat1*rat1); 
      }
    }
    printf("%f\n", i, ans);
  }
}

