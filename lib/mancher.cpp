ある文字列 S が与えられているとする。Manacher では, それぞれの i について文字 i を
中心とする最長回文の半径を記録した配列を線形時間で構築するアルゴリズムである。

vector< int > manacher(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}
