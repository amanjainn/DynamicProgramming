static bool mycmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
  return get<0>(a) * get<1>(a) > get<0>(b) * get<1>(b);
}
int maxHeight(int h[], int w[], int l[], int n) {
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < n; i++) {
    if (l[i] > w[i]) {
      v.push_back(make_tuple(l[i], w[i], h[i]));
    } else {
      v.push_back(make_tuple(w[i], l[i], h[i]));
    }

    if (w[i] > h[i]) {
      v.push_back(make_tuple(w[i], h[i], l[i]));
    } else {
      v.push_back(make_tuple(h[i], w[i], l[i]));
    }

    if (l[i] > h[i]) {
      v.push_back(make_tuple(l[i], h[i], w[i]));
    } else {
      v.push_back(make_tuple(h[i], l[i], w[i]));
    }
  }

  sort(v.begin(), v.end(), mycmp);
  vector<int> ht;
   int ans = 0;
  for (int i = 0; i < 3 * n; i++) {
    ht.push_back(get<2>(v[i]));
    ans=max(ans,get<2>(v[i]));
  }
 
  for (int i = 1; i < 3 * n; i++) {
    for (int j = 0; j < i; j++) {
      if (get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j])) {
        ht[i] = max(ht[i], get<2>(v[i]) + ht[j]);
        ans = max(ans, ht[i]);
      }
    }
  }
  return ans;
}
