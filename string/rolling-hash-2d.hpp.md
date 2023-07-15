---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/base.hpp
    title: string/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash-2d.hpp\"\n\n#line 2 \"string/base.hpp\"\
    \n\nnamespace matumoto {\n  using namespace std;\n}\n#line 4 \"string/rolling-hash-2d.hpp\"\
    \n\n#include <string>\n#include <vector>\n\nnamespace matumoto {\n  // verify:AOJ_ALDS1_14_C\n\
    \  // recomend:{ MOD:2^61-1, base1,base2:random }\n  struct RollingHash2D {\n\
    \    using i128 = __int128_t;\n    using ll = long long;\n    ll mod, base1, base2;\n\
    \    struct CumulativeSum2D {\n      vector<vector<ll>> data;\n      CumulativeSum2D()\
    \ {}\n\n      void set(int y, int x, ll v) {\n        data[y + 1][x + 1] = v;\n\
    \      }\n\n      void build(ll mod) {\n        for (int i = 1; i < static_cast<int>(data.size());\
    \ i++) {\n          for (int j = 1; j < static_cast<int>(data[i].size()); j++)\
    \ {\n            data[i][j] += (data[i][j - 1] + data[i - 1][j] - data[i - 1][j\
    \ - 1]) % mod;\n            if (data[i][j] < 0)\n              data[i][j] += mod;\n\
    \          }\n        }\n      }\n\n      // [ (sy,sx), (gy,gx) )\n      ll query(int\
    \ sy, int sx, int gy, int gx, ll mod) {\n        ll res = (data[gy][gx] - data[gy][sx]\
    \ - data[sy][gx] + data[sy][sx]) % mod;\n        if (res < 0)\n          res +=\
    \ mod;\n        return res;\n      }\n    };\n\n    CumulativeSum2D sum;\n   \
    \ vector<vector<ll>> dat, inv;\n    RollingHash2D(const vector<vector<ll>> &vs,\
    \ ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL << 61) - 1): dat(vs)\
    \ {\n      set_base(B1, B2);\n      set_mod(MOD);\n    }\n    RollingHash2D(const\
    \ vector<string> &s, ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL\
    \ << 61) - 1) {\n      set_base(B1, B2);\n      set_mod(MOD);\n      dat.resize(s.size());\n\
    \      for (int i = 0; i < static_cast<int>(s.size()); i++) {\n        for (char\
    \ c: s[i]) {\n          dat[i].emplace_back(c);\n        }\n      }\n    }\n\n\
    \    void set_mod(ll M) {\n      mod = M;\n    }\n    void set_base(ll B1, ll\
    \ B2) {\n      base1 = B1, base2 = B2;\n    }\n\n    // mod multiprecation\n \
    \   ll mod_mul(ll a, ll b) {\n      i128 res = a;\n      res *= b;\n      res\
    \ = (res >> 61) + (res & mod);\n      if (res >= mod)\n        res -= mod;\n \
    \     return (ll)res;\n    }\n\n    ll pow(ll a, i128 e) {\n      if (e == 0)\n\
    \        return 1;\n      if (e % 2 == 0) {\n        ll res = pow(a, e / 2);\n\
    \        return mod_mul(res, res);\n      }\n      return mod_mul(pow(a, e - 1),\
    \ a);\n    }\n\n    void build() {\n      int h = dat.size(), w = dat[0].size();\n\
    \      inv.assign(h + 1, vector<ll>(w + 1, 0));\n      sum.data.assign(h + 1,\
    \ vector<ll>(w + 1, 0));\n      vector<ll> pow_table1(h + 1), pow_table2(w + 1);\n\
    \n      i128 e = mod - 2;\n      inv[h][w] = mod_mul(pow(base1, h * e), pow(base2,\
    \ w * e));\n      pow_table1[0] = 1;\n      pow_table2[0] = 1;\n\n      for (int\
    \ i = h - 1; i >= 0; i--) {\n        pow_table1[h - i] = mod_mul(base1, pow_table1[h\
    \ - i - 1]);\n        inv[i][w] = mod_mul(base1, inv[i + 1][w]);\n      }\n  \
    \    for (int j = w - 1; j >= 0; j--) {\n        pow_table2[w - j] = mod_mul(base2,\
    \ pow_table2[w - j - 1]);\n        inv[h][j] = mod_mul(base2, inv[h][j + 1]);\n\
    \      }\n      for (int i = h - 1; i >= 0; i--) {\n        for (int j = w - 1;\
    \ j >= 0; j--) {\n          inv[i][j] = mod_mul(inv[i + 1][j + 1], base1);\n \
    \         inv[i][j] = mod_mul(inv[i][j], base2);\n        }\n      }\n      for\
    \ (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n         \
    \ ll val = mod_mul(dat[i][j], pow_table1[i]);\n          val = mod_mul(val, pow_table2[j]);\n\
    \          sum.set(i, j, val);\n        }\n      }\n      sum.build(mod);\n  \
    \  }\n\n    ll find(int sy, int sx, int gy, int gx) {\n      return mod_mul(sum.query(sy,\
    \ sx, gy, gx, mod), inv[sy][sx]);\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nnamespace matumoto {\n  // verify:AOJ_ALDS1_14_C\n  // recomend:{ MOD:2^61-1,\
    \ base1,base2:random }\n  struct RollingHash2D {\n    using i128 = __int128_t;\n\
    \    using ll = long long;\n    ll mod, base1, base2;\n    struct CumulativeSum2D\
    \ {\n      vector<vector<ll>> data;\n      CumulativeSum2D() {}\n\n      void\
    \ set(int y, int x, ll v) {\n        data[y + 1][x + 1] = v;\n      }\n\n    \
    \  void build(ll mod) {\n        for (int i = 1; i < static_cast<int>(data.size());\
    \ i++) {\n          for (int j = 1; j < static_cast<int>(data[i].size()); j++)\
    \ {\n            data[i][j] += (data[i][j - 1] + data[i - 1][j] - data[i - 1][j\
    \ - 1]) % mod;\n            if (data[i][j] < 0)\n              data[i][j] += mod;\n\
    \          }\n        }\n      }\n\n      // [ (sy,sx), (gy,gx) )\n      ll query(int\
    \ sy, int sx, int gy, int gx, ll mod) {\n        ll res = (data[gy][gx] - data[gy][sx]\
    \ - data[sy][gx] + data[sy][sx]) % mod;\n        if (res < 0)\n          res +=\
    \ mod;\n        return res;\n      }\n    };\n\n    CumulativeSum2D sum;\n   \
    \ vector<vector<ll>> dat, inv;\n    RollingHash2D(const vector<vector<ll>> &vs,\
    \ ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL << 61) - 1): dat(vs)\
    \ {\n      set_base(B1, B2);\n      set_mod(MOD);\n    }\n    RollingHash2D(const\
    \ vector<string> &s, ll B1 = (int)1e9 + 7, ll B2 = (int)1e8 + 7, ll MOD = (1LL\
    \ << 61) - 1) {\n      set_base(B1, B2);\n      set_mod(MOD);\n      dat.resize(s.size());\n\
    \      for (int i = 0; i < static_cast<int>(s.size()); i++) {\n        for (char\
    \ c: s[i]) {\n          dat[i].emplace_back(c);\n        }\n      }\n    }\n\n\
    \    void set_mod(ll M) {\n      mod = M;\n    }\n    void set_base(ll B1, ll\
    \ B2) {\n      base1 = B1, base2 = B2;\n    }\n\n    // mod multiprecation\n \
    \   ll mod_mul(ll a, ll b) {\n      i128 res = a;\n      res *= b;\n      res\
    \ = (res >> 61) + (res & mod);\n      if (res >= mod)\n        res -= mod;\n \
    \     return (ll)res;\n    }\n\n    ll pow(ll a, i128 e) {\n      if (e == 0)\n\
    \        return 1;\n      if (e % 2 == 0) {\n        ll res = pow(a, e / 2);\n\
    \        return mod_mul(res, res);\n      }\n      return mod_mul(pow(a, e - 1),\
    \ a);\n    }\n\n    void build() {\n      int h = dat.size(), w = dat[0].size();\n\
    \      inv.assign(h + 1, vector<ll>(w + 1, 0));\n      sum.data.assign(h + 1,\
    \ vector<ll>(w + 1, 0));\n      vector<ll> pow_table1(h + 1), pow_table2(w + 1);\n\
    \n      i128 e = mod - 2;\n      inv[h][w] = mod_mul(pow(base1, h * e), pow(base2,\
    \ w * e));\n      pow_table1[0] = 1;\n      pow_table2[0] = 1;\n\n      for (int\
    \ i = h - 1; i >= 0; i--) {\n        pow_table1[h - i] = mod_mul(base1, pow_table1[h\
    \ - i - 1]);\n        inv[i][w] = mod_mul(base1, inv[i + 1][w]);\n      }\n  \
    \    for (int j = w - 1; j >= 0; j--) {\n        pow_table2[w - j] = mod_mul(base2,\
    \ pow_table2[w - j - 1]);\n        inv[h][j] = mod_mul(base2, inv[h][j + 1]);\n\
    \      }\n      for (int i = h - 1; i >= 0; i--) {\n        for (int j = w - 1;\
    \ j >= 0; j--) {\n          inv[i][j] = mod_mul(inv[i + 1][j + 1], base1);\n \
    \         inv[i][j] = mod_mul(inv[i][j], base2);\n        }\n      }\n      for\
    \ (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n         \
    \ ll val = mod_mul(dat[i][j], pow_table1[i]);\n          val = mod_mul(val, pow_table2[j]);\n\
    \          sum.set(i, j, val);\n        }\n      }\n      sum.build(mod);\n  \
    \  }\n\n    ll find(int sy, int sx, int gy, int gx) {\n      return mod_mul(sum.query(sy,\
    \ sx, gy, gx, mod), inv[sy][sx]);\n    }\n  };\n} // namespace matumoto"
  dependsOn:
  - string/base.hpp
  isVerificationFile: false
  path: string/rolling-hash-2d.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash-2d.hpp
layout: document
redirect_from:
- /library/string/rolling-hash-2d.hpp
- /library/string/rolling-hash-2d.hpp.html
title: string/rolling-hash-2d.hpp
---
