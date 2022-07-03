#pragma once

#include "./base.hpp"

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>

namespace graph_library {
  template <class T>
  class EdgeInterface {
    // TODO: Do implement constructor
    // UnWeightedEdge(from, to)
    // WeightedEdge  (from, to, cost)
  public:
    int &from() {
      return static_cast<T &>(this)->from();
    }

    const int &from() const {
      return static_cast<T &>(this)->from();
    }

    int &to() {
      return static_cast<T &>(this)->to();
    }

    const int &to() const {
      return static_cast<T &>(this)->to();
    }
  };

  template <typename Cost>
  class WeightedEdge: public EdgeInterface<WeightedEdge<Cost>> {
  private:
    int from_, to_;
    Cost cost_;

  public:
    WeightedEdge() = default;
    WeightedEdge(int to_): to_(to_) {}
    WeightedEdge(int to_, Cost cost_): to_(to_), cost_(cost_) {}
    WeightedEdge(int from_, int to_, Cost cost_): from_(from_), to_(to_), cost_(cost_) {}

    bool operator<(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ < rhs.cost_;

      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ <= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ > rhs.cost_;

      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ >= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const WeightedEdge<Cost> &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_ or cost_ != rhs.cost_;
    }

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

    Cost &cost() {
      return cost_;
    }

    const Cost &cost() const {
      return cost_;
    }

    template <typename T>
    friend ostream &operator<<(ostream &os, const WeightedEdge<T> &rhs) {
      os << rhs.from_ << ' ' << rhs.to_ << ' ' << rhs.cost_;
      return os;
    }
  };

  class UnWeightedEdge: public EdgeInterface<UnWeightedEdge> {
  private:
    int from_, to_;

  public:
    UnWeightedEdge() = default;
    UnWeightedEdge(int to_): to_(to_) {}
    UnWeightedEdge(int from_, int to_): from_(from_), to_(to_) {}

    bool operator<(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const UnWeightedEdge &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_;
    }

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

    friend ostream &operator<<(ostream &os, const UnWeightedEdge &rhs) {
      os << rhs.from_ << ' ' << rhs.to_;
      return os;
    }
  };

  template <typename Cost>
  using WeightedEdges = vector<WeightedEdge<Cost>>;

  using UnWeightedEdges = vector<UnWeightedEdge>;


  template <class Edge, bool is_extended_edge = is_base_of_v<EdgeInterface<Edge>, Edge>>
  class Graph {
    static_assert(is_extended_edge, "Edge is not extended edge interface class.");
  };

  template <class Edge>
  class Graph<Edge, true> {
  public:
    using Edges = vector<Edge>;

  private:
    Edges edges_;
    vector<Edges> graph_;
    int size_;

  public:
    Graph() = default;
    Graph(int N): graph_(N), size_(N) {}

    int size() const {
      return size_;
    }

    void add_edge(const Edge &edge) {
      const int &from = edge.from();
      graph_.at(from).push_back(edge);
      edges_.push_back(edge);
    }

    Edge get_edge(int k) const {
      return edges_.at(k);
    }

    Edges edges() const {
      return edges_;
    }

    void pop_back_edge() {
      assert(not edges_.empty());

      const Edge e = edges_.back();
      edges_.pop_back();
      graph_.at(e.from()).pop_back();
    }

    vector<Edges> graph() const {
      return graph_;
    }
  };

  template <typename Cost>
  using WeightedGraph = Graph<WeightedEdge<Cost>>;

  using UnWeightedGraph = Graph<UnWeightedEdge>;

  // graph utility
  template <typename Cost>
  WeightedGraph<Cost> to_weighted(const UnWeightedGraph &ug, Cost weight = 1) {
    WeightedGraph<Cost> wg(ug.size());
    auto edges = ug.edges();
    for (auto edge: edges) {
      wg.add_edge(WeightedEdge<Cost>(edge.from(), edge.to(), weight));
    }
    return wg;
  }

  template <typename Cost>
  UnWeightedGraph to_unweighted(const WeightedGraph<Cost> &wg) {
    UnWeightedGraph ug(wg.size());
    auto edges = wg.edges();
    for (auto edge: edges) {
      ug.add_edge(UnWeightedEdge(edge.from(), edge.to()));
    }
    return ug;
  }
} // namespace graph_library
