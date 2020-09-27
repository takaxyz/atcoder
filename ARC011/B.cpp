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
  int n;
  cin >> n;
  vector<string> ans;
  REP(i,n){
    string s;
    cin >> s;
    transform(ALL(s), s.begin(), ::tolower);
    string t;
    for(auto c: s){
      if(c=='b' || c == 'c'){
        t += "1";
      }else if(c=='d' || c == 'w'){
        t += "2";
      }else if(c=='t' || c == 'j'){
        t += "3";
      }else if(c=='f' || c == 'q'){
        t += "4";
      }else if(c=='l' || c == 'v'){
        t += "5";
      }else if(c=='s' || c == 'x'){
        t += "6";
      }else if(c=='p' || c == 'm'){
        t += "7";
      }else if(c=='h' || c == 'k'){
        t += "8";
      }else if(c=='n' || c == 'g'){
        t += "9";
      }else if(c=='z' || c == 'r'){
        t += "0";
      }
    }
    if(t.size())ans.emplace_back(t);
  }

  REP(i,ans.size()){
    cout << ans[i];
    if(i<ans.size()-1)cout << " ";
  }
  cout << endl;
}


