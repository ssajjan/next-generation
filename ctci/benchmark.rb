require 'benchmark'
require 'colorize'
str = "2\n4 2\n1 2\n1 3\n1\n3 1\n2 3\n2\n"
class Graph
  def self.get_distance input
    idx, i = 0, 0
    test_cases = input[idx].to_i
    until i == test_cases do
      node_num = input[idx+=2].to_i
      edge_num = input[idx+=2].to_i
      g = new(node_num, edge_num)
      a = 0
      until a == edge_num do
        g.add_edge input[idx+=2].to_i, input[idx+=2].to_i
        a+=1
      end
      puts g.distance input[idx+=2].to_i
      i += 1
    end
  end
  def initialize node_num, edge_num
    @node_num = node_num
    @edges = Array.new(edge_num + 1)
    i = 0
    until i == node_num + 1 do
      @edges[i] = []
      i+=1
    end
  end
  def add_edge from, to
    @edges[from] << to
    @edges[to] << from
  end
  def distance start
    bfs(start)[1..-1].join(" ")
  end
  def bfs start
    visited = Array.new(@node_num + 1, -1)
    visited[start] = 1
    count = 0
    queue = []
    queue.push @edges[start]
    until queue.empty? do
      edges, i = queue.shift, 0
      len = edges.length
      count += 6
      until i == len do
        curr = edges[i]
        unless visited[curr] > 0
          visited[curr] = count
          queue.push @edges[curr]
        end
        i+=1
      end
    end
    visited[start] = ""
    visited
  end
end

def standard input
  idx = 0
  test_cases = input[idx].to_i
  i = 0
  until i == test_cases do
    node_num = input[idx+=2].to_i
    edge_num = input[idx+=2].to_i
    g = Graph.new(node_num, edge_num)
    a = 0
    until a == edge_num do
      g.add_edge input[idx+=2].to_i, input[idx+=2].to_i
      a+=1
    end
    puts g.distance input[idx+=2].to_i
    i += 1
  end
end

Graph.get_distance(str)
