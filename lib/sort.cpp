  // 添字の配列を渡してそれが対応する配列の値に応じてソートする
  sort(ALL(ids),[&](const int& i, const int& j){
      return a[i] と a[j] を何らかのルールで比較
    }
  );


// firstが降順、secondが昇順
bool cmp(const P &a, const P &b){
    return a.first != b.first
        ? a.first > b.first
        : a.second < b.second;
}
