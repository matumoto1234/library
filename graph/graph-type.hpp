#pragma once

#include "./base.hpp"

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace library_graph {
  namespace {
    struct EdgeInterface {
      virtual int &from() = 0;
      virtual int &to() = 0;

      // If you want to get high performance, should comment out below line.
      virtual ~EdgeInterface() = default;
    };
  } // namespace

  template <typename Cost>
  struct WeightedEdge: public EdgeInterface {
  private:
    int from_, to_;
    Cost cost_;

  public:
    WeightedEdge() = default;
    WeightedEdge(int to_): to_(to_) {}
    WeightedEdge(int to_, Cost cost_): to_(to_), cost_(cost_) {}
    WeightedEdge(int from_, int to_, Cost cost_): from_(from_), to_(to_), cost_(cost_) {}

    bool operator<(const WeightedEdge &rhs) const {
      return cost_ < rhs.cost_;
    }
    int &from() override {
      return from_;
    }
    int &to() override {
      return to_;
    }
    Cost &cost() {
      return cost_;
    }
  };


  struct UnWeightedEdge: public EdgeInterface {
  private:
    int from_, to_;

  public:
    UnWeightedEdge() = default;
    UnWeightedEdge(int to_): to_(to_) {}
    UnWeightedEdge(int from_, int to_): from_(from_), to_(to_) {}

    int &from() override {
      return from_;
    }

    int &to() override {
      return to_;
    }
  };

  template <typename Cost>
  using WeightedEdges = vector<WeightedEdge<Cost>>;

  using UnWeightedEdges = vector<UnWeightedEdge>;

  namespace {
    template <typename Edge>
    struct GraphInterface {
    private:
      using Edges = vector<Edge>;

    public:
      virtual int size() const = 0;
      virtual Edge get_edge(int k) const = 0;
      virtual Edges edges() const = 0;
      virtual vector<Edges> graph() const = 0;
    };
  } // namespace

  template <typename Cost>
  struct WeightedGraph: public GraphInterface<WeightedEdge<Cost>> {
  private:
    WeightedEdges<Cost> edges_;
    vector<WeightedEdges<Cost>> graph_;
    int size_;

  public:
    WeightedGraph(int N): graph_(N), size_(N) {}

    void add_edge(int from, int to, Cost cost) {
      graph_.at(from).emplace_back(to, cost);
      edges_.emplace_back(from, to, cost);
    }

    // Number of vertices
    int size() const {
      return size_;
    }

    WeightedEdge<Cost> get_edge(int k) const {
      return edges_.at(k);
    }

    WeightedEdges<Cost> edges() const {
      return edges_;
    }

    vector<WeightedEdges<Cost>> graph() const {
      return graph_;
    }
  };


  struct UnWeightedGraph: public GraphInterface<UnWeightedEdge> {
  private:
    UnWeightedEdges edges_;
    vector<UnWeightedEdges> graph_;
    int size_;

  public:
    UnWeightedGraph(int N): graph_(N), size_(N) {}

    void add_edge(int from, int to) {
      graph_.at(from).emplace_back(to);
      edges_.emplace_back(from, to);
    }

    // Number of vertices
    int size() const {
      return size_;
    }

    UnWeightedEdge get_edge(int k) const {
      return edges_.at(k);
    }

    UnWeightedEdges edges() const {
      return edges_;
    }

    vector<UnWeightedEdges> graph() const {
      return graph_;
    }
  };
} // namespace library_graph
