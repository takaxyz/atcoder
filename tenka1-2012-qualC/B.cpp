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
  map<char, int> mpset;

  string s;
  cin >> s;

  char x='0';
  int i=0;
  vector<string> cards;
  while(i < s.size() && x == '0'){
    char mark = s[i];

    if(s[i+1]=='1'){
      mpset[mark]++;
      cards.emplace_back(s.substr(i,3));
      i+=3;
    }else{
      if(s[i+1]=='J' || s[i+1]=='Q' || s[i+1]=='K'||s[i+1]=='A')mpset[mark]++;
      cards.emplace_back(s.substr(i,2));
      i+=2;
    }

    for(auto v: mpset){
      if(v.second == 5){
        x = v.first;
      }
    }
  }

  REP(i,cards.size()){
    if(cards[i][0] == x && (cards[i][1] == '1' || cards[i][1] == 'J' || cards[i][1] == 'Q' || cards[i][1] == 'K' || cards[i][1] == 'A')){
      continue;
    }
    cout << cards[i];
  }
  if(cards.size()==5)cout << 0;
  cout << endl;
}

