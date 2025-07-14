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
  int t;
  cin >> t;
  REP(_,t){
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n)cin >> a[i];

    int cp=0;
    REP(i,n)if(a[i]>0)cp++;

    if(cp==n || cp ==0){
      sort(ALL(a));

      bool ok=true;
      FOR(i,1,n-1){
        if(a[i-1] * a[i+1] != a[i]*a[i])ok=false;
      }

      cout << (ok ? "Yes" : "No") << endl;
    }else{
      if(n%2==0 && n/2 != cp){
        cout << "No" << endl;
        continue;;
      }
      if(n%2==1 && n/2 != cp && (n/2 + 1) != cp){
        cout << "No" << endl;
        continue;;
      }

      vector<ll> b(n);
      REP(i,n)b[i] = abs(a[i]);
      bool ok =true;
      REP(i,n-1){
        if(b[i] != b[i+1])ok=false;
      }
      if(ok){
        cout << "Yes" << endl;
        continue;;
      }
    
      vector<pair<ll,ll>> c(n);
      REP(i,n)c[i] = {abs(a[i]),a[i]};
      sort(ALL(c));
      ok=true;

      FOR(i,1,n-1){
        if(c[i-1].second * c[i+1].second != c[i].second * c[i].second)ok=false;
      }

      cout << (ok ? "Yes" : "No") << endl;


    }
  }
}

