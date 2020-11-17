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

int main(){
  int x, y;
  string W;
  cin >> x >> y >> W;
  x--; y--;

  int c[9][9];
  REP(i,9)REP(j,9){
    char s;
    cin >> s;
    c[i][j] = s - '0';
  }

  map<string, P> mp;
  mp["R"] = {0,1};
  mp["L"] = {0,-1};
  mp["U"] = {-1,0};
  mp["D"] = {1,0};
  mp["RU"] = {-1,1};
  mp["RD"] = {1,1};
  mp["LU"] = {-1,-1};
  mp["LD"] = {1,-1};

  int dy = mp[W].first; 
  int dx = mp[W].second; 
  REP(i,4){
    cout << c[y][x];
    if(x == 0 && dx != 0)dx=1;
    if(x == 8 && dx != 0)dx=-1;
    if(y == 0 && dy != 0)dy=1;
    if(y == 8 && dy != 0)dy=-1;

    y += dy;
    x += dx;
  }
  cout << endl;

}

