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

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  auto f = [&](double p) -> bool{
    vector<double> sum(n+1), msum(n+1);
    REP(i,n){
      if(s[i]=='o'){
        sum[i+1] += sum[i] + 1 - p;
      }else{
        sum[i+1] += sum[i] - p;  
      }
    }

    FOR(i,1,n+1)msum[i] = min(msum[i-1], sum[i]);

    int l = 0;
    int cnt = 0;
    double mi = 1e8; 
    REP(r, n){
      if(s[r]=='o')cnt++;

      if(cnt < k)continue;
      while(cnt >= k){
        mi = min(mi, sum[l]);
        if(s[l]=='o')cnt--;
        l++;
      }
      //printf("%.10f\n", mi);

      if(sum[r+1] - msum[l] >= 0)return true; 
    }

    return false;
  };

  double ok=0, ng=1;

  REP(_,25){
    double mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  printf("%.10f\n", ok);
}

