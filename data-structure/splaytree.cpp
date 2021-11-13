#include <bits/stdc++.h>
using namespace std;

template<typename T, T (*op)(T, T) = nullptr>
struct splay_tree {
  struct node {
    node *left, *right, *parent;
    int size;
    T calc_value, value;

    node(): left(nullptr), right(nullptr), parent(nullptr), size(1) {}

    // 回転
    void rotate() {
      node *pp, *p, *c;
      p = this->parent;
      pp = p->parent;

      if (p->left == this) {
        c = this->right;
        this->right = p;
        p->left = c;
      } else {
        c = this->left;
        this->left = p;
        p->right = c;
      }

      if (pp and pp->left == p) pp->left = this;
      if (pp and pp->right == p) pp->right = this;
      this->parent = pp;
      p->parent = this;
      if (c) c->parent = p;

      p->update();
      this->update();
    }

    // 根:0, 左:1, 右:-1
    int state() {
      if (!this->parent) return 0;
      if (this->parent->left == this) return 1;
      if (this->parent->right == this) return -1;
      return 0;
    }

    // 根になるまで回転
    void splay() {
      while (this->state() != 0) {
        // 親が根
        if (this->parent->state() == 0) {
          this->rotate();
        } else if (this->state() == this->parent->state()) {
          this->parent->rotate();
          this->rotate();
        } else {
          this->rotate();
          this->rotate();
        }
      }
    }

    // 左右の子に対して操作
    void update() {
      this->size = 1;
      this->calc_value = value;
      if (this->left) {
        this->size += left->size;
        if (op) this->calc_value = op(this->calc_value, this->left->calc_value);
      }
      if (this->right) {
        this->size += right->size;
        if (op) this->calc_value = op(this->calc_value, this->right->calc_value);
      }
    }
  };

  node *_root;
  vector<node> nodes;
  splay_tree(int n): nodes(n) {
    for (int i = 0; i < n - 1; i++) {
      nodes[i].parent = &nodes[i + 1];
      nodes[i + 1].left = &nodes[i];
      nodes[i + 1].update();
    }
    _root = &nodes[n - 1];
  }

  T &operator[](int idx) {
    get(idx, _root);
    _root->update();
    return _root->value;
  }

  node *&root() { return _root; }

  // rootの左からのidx番目の頂点を根にして返す
  node *get(int idx, node *root) {
    node *now = root;
    while (true) {
      int lsize = now->left ? now->left->size : 0;
      if (idx < lsize) now = now->left;
      if (idx == lsize) {
        now->splay();
        break;
      }
      if (idx > lsize) {
        now = now->right;
        idx = idx - lsize - 1;
      }
    }
    _root = now;
    return now;
  }

  // lrootとrrootをマージ
  node *merge(node *lroot, node *rroot) {
    if (!lroot) return rroot;
    if (!rroot) return lroot;
    lroot = get(lroot->size - 1, lroot);
    lroot->right = rroot;
    rroot->parent = lroot;
    lroot->update();
    return lroot;
  }

  // [0,n) -> [0,idx),[idx,n)
  pair<node *, node *> split(int idx, node *root) {
    if (idx == 0) return { nullptr, root };
    if (idx == root->size) return { root, nullptr };

    root = get(idx, root);
    node *lroot, *rroot;
    lroot = root->left;
    rroot = root;
    rroot->left = nullptr;
    lroot->parent = nullptr;
    rroot->update();
    return { lroot, rroot };
  }

  node *insert(int idx, node *tmp, node *root) {
    auto trees = split(idx, root);
    node *lroot = trees.first;
    node *rroot = trees.second;
    return merge(merge(lroot, tmp), rroot);
  }

  pair<node *, node *> erase(int idx, node *root) {
    root = get(idx, root);
    node *lroot = root->left;
    node *rroot = root->right;
    if (lroot) lroot->parent = nullptr;
    if (rroot) rroot->parent = nullptr;
    root->left = nullptr;
    root->right = nullptr;
    root->update();
    return { merge(lroot, rroot), root };
  }

  node *shift(int l, int r, node *root) {
    auto temp = erase(r, root);
    root = temp.first;
    node *node = temp.second;
    return insert(l, node, root);
  }

  pair<node *, int> prod(int l, int r, node *root) {
    node *lroot, *croot, *rroot;
    auto temp = split(r + 1, root);
    rroot = temp.second;
    temp = split(l, temp.first);
    lroot = temp.first;
    croot = temp.second;
    int ans = croot->calc_value;
    return { merge(merge(lroot, croot), rroot), ans };
  }
};

int op(int a, int b) {
  return min(a, b);
}

int main() {
  int n, q;
  cin >> n >> q;

  splay_tree<int, op> nodes(n);

  for (int i = 0; i < n; i++) {
    cin >> nodes[i];
    // cin >> nodes[i].value;
    // nodes[i].update();
  }

  // splay_tree<int>::node *root = &nodes[n - 1];

  for (int i = 0; i < q; i++) {
    int ord, pos, val, l, r;
    cin >> ord;
    if (ord == 0) {
      cin >> l >> r;
      nodes.root() = nodes.shift(l, r, nodes.root());
    }
    if (ord == 1) {
      cin >> l >> r;
      auto temp = nodes.prod(l, r, nodes.root());
      nodes.root() = temp.first;
      cout << temp.second << endl;
    }
    if (ord == 2) {
      cin >> pos >> val;
      nodes.root() = nodes.get(pos, nodes.root());
      nodes.root()->value = val;
      nodes.root()->update();
    }
  }
}
