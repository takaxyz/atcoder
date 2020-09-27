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

int md[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int conv(int m, int d){
  return md[m-1] + d;
}
int main(){
  vi h(367,0);

  REP(i,12){
    md[i+1] += md[i];
  }

  FOR(i,1,367)if(i%7==1 || i%7==0)h[i]=1;

  int n;
  cin >> n;
  vector<P> md;
  REP(i,n){
    int m,d;
    char c;
    cin >> m >> c >> d;
    md.emplace_back(m,d);
  }
  sort(ALL(md));

  REP(i,n){
    int x = conv(md[i].first, md[i].second);
    while(h[x]==1 && x < 367)x++;
    if(x<367)h[x]=1;
  }

  //FOR(i,1,366)cout << h[i] << " ";

  int cnt=0;
  int ans=0;
  FOR(i,1,366){
    if(h[i])cnt++;
    else cnt=0;
    chmax(ans,cnt);
  }
    chmax(ans,cnt);
  cout << ans << endl;
}

