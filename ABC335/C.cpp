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
const int MOD = 1e9 + 7;

int main(){
  int n,q;
  cin >> n >> q;
  vector<P> pos(n);
  REP(i,n)pos[i] = {n - i, 0};

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int x = pos.back().first;
      int y = pos.back().second;
      char c;
      cin >> c;
      switch(c){
        case 'R':
        x++;
        break;

        case 'L':
        x--;
        break;

        case 'U':
        y++;
        break;
        
        case 'D':
        y--;
        break;
      }
      pos.emplace_back(x,y);
    }else{
      int p;
      cin >> p;
      cout << pos[pos.size()-p].first << " " << pos[pos.size()-p].second << endl;
    }
  }
}

