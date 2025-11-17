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
//#define mp make_pair
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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


void solve(){
  map<char,int> mp;
  mp['A'] = 0;
  mp['B'] = 1;
  mp['C'] = 3;
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i,h)cin >> s[i];

    deque<tuple<int,int,int,int>> q;

    vector dist(h, vector(w,vi(4,INF)));

    // i,j,cost,dir
    q.push_back({0,-1,0,0});
    while(q.size()){
      auto [i,j,cost,dir] = q.front();
      q.pop_front();

      if(i == h-1 && j == w-1 && dir == 0){
        cout << cost << endl;
        return;
      }

      int ni = i + dx[dir];
      int nj = j + dy[dir];

      if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;

      REP(ndir,4){
        if((dir^ndir) == 2)continue;

        if((dir ^ ndir) == mp[s[ni][nj]]){
          if(dist[ni][nj][ndir] > cost){
            dist[ni][nj][ndir] = cost;
            q.push_front({ni,nj,cost,ndir});
          }
        }else{
          if(dist[ni][nj][ndir] > cost+1){
            dist[ni][nj][ndir] = cost+1;
            q.push_back({ni,nj,cost+1,ndir});
          }
        }
      }

    }

}



int main(){
  int t;
  cin >> t;
  REP(_,t){
    solve();
  }
}

