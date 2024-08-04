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

int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};

int main(){
  int h,w;
  cin >> h >> w;
  int si,sj;
  cin >> si >> sj;
  si--; sj--;
  vector<string> c(h);
  REP(i,h)cin >> c[i];
  string x;
  cin >> x;

  for(auto d: x){
    int i;
    if(d == 'L'){
      i = 0;
    }else if(d == 'R'){
      i = 1;
    }else if(d == 'U'){
      i = 2;
    }else{
      i = 3;
    }

    int ni = si + di[i];
    int nj = sj + dj[i];

    if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
    if(c[ni][nj]=='#')continue;
    si = ni; sj = nj;
    //cout << d << " " << si + 1 << " " << sj + 1 << endl;
  }

  cout << si + 1 << " " << sj + 1 << endl;


}

