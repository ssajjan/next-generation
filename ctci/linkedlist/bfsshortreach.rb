require 'pry'
#INPUT num_of_nodes & edges
#Create an Adjaceny list with Nodes
#Node has a pointer to linkedlist of :edges
#Edge has a pointer to a :node and to next :edge

class Queue
  Node = Struct.new(:data, :next)
  def enqueue data
    new_node = Node.new data
    if empty?
      @tail.next = new_node
    else
      @head = new_node 
    end
    @tail = new_node
  end
  def dequeue 
    data = @head.data
    @head = @head.next
    data
  end
  def empty?
    @head && @tail
  end
end

class DirectedGraph
  Node = Struct.new(:name, :edges)
  Edge = Struct.new(:node, :next)
  def initialize num_of_nodes, edges, start
    @num_of_nodes = num_of_nodes
    name = -1
    @nodes = Array.new(@num_of_nodes) { Node.new name+=1 }
    @start = start
    edges.each {|edge| add_edge edge}
  end
  def distance_from_start
    visited = bfs
    visited.each_with_object("") do |visit, result| 
      next if visit == 0
      result << visit ? "#{visit} " : "-1 "
    end
  end
  def bfs root_node=@start
    visited = Array.new(@num_of_nodes, nil)
    count = 0
    q = Queue.new
    q.enqueue root_node
    visited[root_node.name] = count
    until q.empty?
      curr_node = q.dequeue
      edges = curr_node.edges
      count+=6
      while edges
        unless visited[edges.node.name]
          q.enqueue edges.node
          visited[edges.node.name] = count
        end
        edges = edges.next
      end
    end
    visited
  end
  def add_edge edge
    from, to = edge
    from -=1
    to -=1
    connect_edge from, to
    connect_edge to, from
  end
  def connect_edge from, to
    new_edge = Edge.new(@nodes[to])
    binding.pry
    if @nodes[from].edges
      new_edge.next = @nodes[from].edges
    end
    @nodes[from].edges = new_edge
  end
end


input = gets(nil).split("\n").map {|line| line.split(" ").map(&:to_i) }
test_cases = input.pop.first
test_cases.times do
  num_of_nodes, num_of_edges = input.pop
  edges = Array.new(num_of_edges) { input.pop }
  start = input.pop
  g = DirectedGraph.new(num_of_nodes, edges, start)
  puts g.distance_from_start
end
