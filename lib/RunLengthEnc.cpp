vector<pair<char, int>> RunLengthEncoding(string& S) {
  if (S.empty()) return {};
  vector<pair<char, int>> ret;
  char c = S[0];
  int n = 1;
  for (int i = 1; i < (int)S.size(); i++) {
    if (S[i] == c)
      n++;
    else {
      ret.emplace_back(c, n);
      c = S[i], n = 1;
    }
  }
  ret.emplace_back(c, n);
  return ret;
}
