#pragma once

#include "../graph/graph-type.hpp"
#include "./base.hpp"

#include <algorithm>
#include <cstdint>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

namespace string_library {
  class HuffmanEdge: public graph_library::EdgeInterface<HuffmanEdge> {
    int from_, to_, bit_;

  public:
    HuffmanEdge() = default;
    HuffmanEdge(int to): to_(to) {}
    HuffmanEdge(int from, int to): from_(from), to_(to) {}
    HuffmanEdge(int from, int to, int bit): from_(from), to_(to), bit_(bit) {}

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    int &bit() {
      return bit_;
    }

    const int &bit() const {
      return bit_;
    }

    friend ostream &operator<<(ostream &os, const HuffmanEdge &rhs) {
      os << "from:" << rhs.from_ << " to:" << rhs.to_ << " bit:" << rhs.bit_;
      return os;
    }
  };


  class HuffmanCoding {
    graph_library::Graph<HuffmanEdge> binary_tree_;
    unordered_map<int, vector<bool>> huffman_code_;
    unordered_map<char, int> ch_to_idx_, frequency_;
    unordered_map<int, char> idx_to_ch_;
    string unique_s_;

    void dfs(const vector<vector<HuffmanEdge>> &adj_list, int v, int pre) {
      for (const auto &e: adj_list[v]) {
        const int &to = e.to();
        if (to == pre)
          continue;

        huffman_code_[to] = huffman_code_[v];
        huffman_code_[to].push_back(bool(e.bit()));

        dfs(adj_list, to, v);
      }
    }

  public:
    HuffmanCoding(const string &s) {
      for (const char &ch: s) {
        frequency_[ch]++;
      }

      unique_s_ = s;
      sort(unique_s_.begin(), unique_s_.end());
      unique_s_.erase(unique(unique_s_.begin(), unique_s_.end()), unique_s_.end());

      for (int i = 0; i < int(unique_s_.size()); i++) {
        const char &ch = unique_s_[i];
        ch_to_idx_[ch] = i;
        idx_to_ch_[i] = ch;
      }

      // count, index
      using pic = pair<int, int>;
      priority_queue<pic, vector<pic>, greater<pic>> pq;

      for (const auto &[ch, cnt]: frequency_) {
        pq.emplace(cnt, ch_to_idx_.at(ch));
      }

      int idx = unique_s_.size();
      const int nodes_count = idx + idx + 1;

      if (int(pq.size()) == 1) {
        pq.emplace(/*count=*/0, nodes_count /*to 0-indexed*/ - 1);
      }

      binary_tree_ = graph_library::Graph<HuffmanEdge>(nodes_count);

      constexpr int LEFT_BIT = 0;
      constexpr int RIGHT_BIT = 1;

      while (int(pq.size()) >= 2) {
        const auto [cnt_left, idx_left] = pq.top();
        pq.pop();

        const auto [cnt_right, idx_right] = pq.top();
        pq.pop();

        binary_tree_.add_edge(HuffmanEdge(idx_left, idx, LEFT_BIT));
        binary_tree_.add_edge(HuffmanEdge(idx, idx_left, LEFT_BIT));

        binary_tree_.add_edge(HuffmanEdge(idx_right, idx, RIGHT_BIT));
        binary_tree_.add_edge(HuffmanEdge(idx, idx_right, RIGHT_BIT));
        pq.emplace(cnt_left + cnt_right, idx);
        idx++;
      }

      dfs(binary_tree_.graph(), /*root=*/idx - 1, /*not exist node=*/-1);
    }

    graph_library::Graph<HuffmanEdge> binary_tree() const {
      return binary_tree_;
    }

    char index_to_char(int idx) const {
      return idx_to_ch_.at(idx);
    }

    int char_to_index(char ch) const {
      return ch_to_idx_.at(ch);
    }

    string unique_string() const {
      return unique_s_;
    }

    vector<bool> code(char ch) const {
      int idx = ch_to_idx_.at(ch);
      return huffman_code_.at(idx);
    }

    unordered_map<char, int> frequency() const {
      return frequency_;
    }
  };
} // namespace string_library
