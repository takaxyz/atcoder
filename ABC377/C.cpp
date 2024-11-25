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
  ll n;
  int m;
  cin >> n >> m;
  set<P> st;

  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    st.insert({a,b});
    for(int i = -2; i < 3; i++){
      for(int j = -2; j < 3; j++){
        if(abs(i)+abs(j) != 3)continue;
        if(i==0 || j ==0)continue;
        int na = a + i;
        int nb = b + j;
        if(na < 0 || na >= n || nb < 0 || nb >= n)continue;
        st.insert({na,nb});
      }
    }
  }

  cout << n*n - st.size() << endl;
}

