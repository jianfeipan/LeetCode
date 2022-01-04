class UnionFind {
public:
  UnionFind(size_t n) {
     root.resize(n);
     for (int i = 0; i < n; ++i) root[i] = i;
  }
  
  int findRoot(int x) {
     int r, y = x, t;
     while(root[x] != x) x = root[x];
     r = x;
     while(root[y] != y) {
        t = root[y]; root[y] = r; y = t; 
     }
     return r; 
  }

  void merge(int x, int y) {
     int r0 = findRoot(x), r1 = findRoot(y);
     if (r0 == r1) return;
     root[r1] = r0;
  }
  
private:
   vector<int> root;
};
