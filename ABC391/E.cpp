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
  int n;
  string s;
  cin >> n >> s;
  int m = 1;
  REP(_,n)m*=3;
  m = (m-1)/2;

  vector<string> b(m, "   ");
  vi cost(m);
  int p = m - 1;
  REP(i,s.size()/3){
    int np = (p-1)/3;
    int ni;
    if(p % 3 == 0)ni=0;
    else if(p % 3 == 2)ni=1;
    else ni = 2; 

    string t = s.substr(i*3,3);
    b[p] = t;
    int cnt0 = count(ALL(t),'0');
    if(cnt0 == 3){
      b[np][ni]='0';
      cost[p] = 2;
    }else if(cnt0 == 2){
      b[np][ni]='0';
      cost[p] = 1;
    }else if(cnt0 == 1){
      b[np][ni]='1';
      cost[p] = 1;
    }else{
      b[np][ni]='1';
      cost[p] = 2;
    }
    p--;
  }

  while(p > 0){
    int np = (p-1)/3;
    int ni;
    if(p % 3 == 0)ni=0;
    else if(p % 3 == 2)ni=1;
    else ni = 2; 

    string t = b[p];
    int cnt0 = count(ALL(t),'0');
    if(cnt0 == 3){
      b[np][ni]='0';
      cost[p] = 2;
    }else if(cnt0 == 2){
      b[np][ni]='0';
      cost[p] = 1;
    }else if(cnt0 == 1){
      b[np][ni]='1';
      cost[p] = 1;
    }else{
      b[np][ni]='1';
      cost[p] = 2;
    }
    p--;
  }


  // REP(i,m){
  //   printf("%d %s %d\n",i,b[i].c_str(), cost[i]);
  // }

  auto dfs = [&](int p, auto dfs) -> int {
    //fprintf(stderr, "%d\n", p);
    if(p >= m/3)return cost[p];
    vi ret(3);
    REP(i,3)ret[i] = dfs(p * 3+i+1, dfs);

    // printf("ret: %d %d %d\n",ret[0],ret[1],ret[2]);
    // printf("%s\n",b[p].c_str());
    int val = 0;
    if(b[p] == "000" || b[p] == "111"){
      REP(i,3)val += ret[i];
      val -= max(ret[0], max(ret[1], ret[2]));
    }else if(b[p] == "011" || b[p] == "100"){
      val = min(ret[0], ret[1]);
    }else if(b[p] == "101" || b[p] == "010"){
      val =  min(ret[0], ret[2]);
    }else if(b[p] == "110" || b[p] == "001"){
      val =  min(ret[1], ret[2]);
    }

    return cost[p] = val;
  };

  dfs(0,dfs);
  cout << cost[0] << endl;
}


