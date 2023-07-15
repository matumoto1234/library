---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/graph-type.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../graph/graph-type.hpp\"\n#include \"./base.hpp\"\
    \n\n#include <algorithm>\n#include <cstdint>\n#include <queue>\n#include <string>\n\
    #include <unordered_map>\n#include <utility>\n\nnamespace matumoto {\n  class\
    \ HuffmanEdge: public matumoto::EdgeInterface<HuffmanEdge> {\n    int from_, to_,\
    \ bit_;\n\n  public:\n    HuffmanEdge() = default;\n    HuffmanEdge(int to): to_(to)\
    \ {}\n    HuffmanEdge(int from, int to): from_(from), to_(to) {}\n    HuffmanEdge(int\
    \ from, int to, int bit): from_(from), to_(to), bit_(bit) {}\n\n    int &from()\
    \ {\n      return from_;\n    }\n\n    const int &from() const {\n      return\
    \ from_;\n    }\n\n    int &to() {\n      return to_;\n    }\n\n    const int\
    \ &to() const {\n      return to_;\n    }\n\n    int &bit() {\n      return bit_;\n\
    \    }\n\n    const int &bit() const {\n      return bit_;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const HuffmanEdge &rhs) {\n      os << \"from:\"\
    \ << rhs.from_ << \" to:\" << rhs.to_ << \" bit:\" << rhs.bit_;\n      return\
    \ os;\n    }\n  };\n\n\n  class HuffmanCoding {\n    matumoto::Graph<HuffmanEdge>\
    \ binary_tree_;\n    unordered_map<int, vector<bool>> huffman_code_;\n    unordered_map<char,\
    \ int> ch_to_idx_, frequency_;\n    unordered_map<int, char> idx_to_ch_;\n   \
    \ string unique_s_;\n\n    void dfs(const vector<vector<HuffmanEdge>> &adj_list,\
    \ int v, int pre) {\n      for (const auto &e: adj_list[v]) {\n        const int\
    \ &to = e.to();\n        if (to == pre)\n          continue;\n\n        huffman_code_[to]\
    \ = huffman_code_[v];\n        huffman_code_[to].push_back(bool(e.bit()));\n\n\
    \        dfs(adj_list, to, v);\n      }\n    }\n\n  public:\n    HuffmanCoding(const\
    \ string &s) {\n      for (const char &ch: s) {\n        frequency_[ch]++;\n \
    \     }\n\n      unique_s_ = s;\n      sort(unique_s_.begin(), unique_s_.end());\n\
    \      unique_s_.erase(unique(unique_s_.begin(), unique_s_.end()), unique_s_.end());\n\
    \n      for (int i = 0; i < int(unique_s_.size()); i++) {\n        const char\
    \ &ch = unique_s_[i];\n        ch_to_idx_[ch] = i;\n        idx_to_ch_[i] = ch;\n\
    \      }\n\n      // count, index\n      using pic = pair<int, int>;\n      priority_queue<pic,\
    \ vector<pic>, greater<pic>> pq;\n\n      for (const auto &[ch, cnt]: frequency_)\
    \ {\n        pq.emplace(cnt, ch_to_idx_.at(ch));\n      }\n\n      int idx = unique_s_.size();\n\
    \      const int nodes_count = idx + idx + 1;\n\n      if (int(pq.size()) == 1)\
    \ {\n        pq.emplace(/*count=*/0, nodes_count /*to 0-indexed*/ - 1);\n    \
    \  }\n\n      binary_tree_ = matumoto::Graph<HuffmanEdge>(nodes_count);\n\n  \
    \    constexpr int LEFT_BIT = 0;\n      constexpr int RIGHT_BIT = 1;\n\n     \
    \ while (int(pq.size()) >= 2) {\n        const auto [cnt_left, idx_left] = pq.top();\n\
    \        pq.pop();\n\n        const auto [cnt_right, idx_right] = pq.top();\n\
    \        pq.pop();\n\n        binary_tree_.add_edge(HuffmanEdge(idx_left, idx,\
    \ LEFT_BIT));\n        binary_tree_.add_edge(HuffmanEdge(idx, idx_left, LEFT_BIT));\n\
    \n        binary_tree_.add_edge(HuffmanEdge(idx_right, idx, RIGHT_BIT));\n   \
    \     binary_tree_.add_edge(HuffmanEdge(idx, idx_right, RIGHT_BIT));\n       \
    \ pq.emplace(cnt_left + cnt_right, idx);\n        idx++;\n      }\n\n      dfs(binary_tree_.graph(),\
    \ /*root=*/idx - 1, /*not exist node=*/-1);\n    }\n\n    matumoto::Graph<HuffmanEdge>\
    \ binary_tree() const {\n      return binary_tree_;\n    }\n\n    char index_to_char(int\
    \ idx) const {\n      return idx_to_ch_.at(idx);\n    }\n\n    int char_to_index(char\
    \ ch) const {\n      return ch_to_idx_.at(ch);\n    }\n\n    string unique_string()\
    \ const {\n      return unique_s_;\n    }\n\n    vector<bool> code(char ch) const\
    \ {\n      int idx = ch_to_idx_.at(ch);\n      return huffman_code_.at(idx);\n\
    \    }\n\n    unordered_map<char, int> frequency() const {\n      return frequency_;\n\
    \    }\n  };\n} // namespace matumoto\n"
  dependsOn: []
  isVerificationFile: false
  path: string/huffman.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/huffman.hpp
layout: document
redirect_from:
- /library/string/huffman.hpp
- /library/string/huffman.hpp.html
title: string/huffman.hpp
---
