require_relative 'queue'

def benchmark
  b = Time.now
  yield
  a = Time.now
  "#{a - b} ms"
end

class Node
  attr_accessor :successors
  def initialize name
    @name = name
    @visited = false
    @successors = []
  end
  def visited?
    @visited
  end
  def visited!
    @visited = true
  end
end

class DirectedAdjacencyList
  def initialize args={}
    @nodes, name = {}, 0
    args[:nodes].times do
      @nodes[name+=1] = Node.new name
    end
    args[:edges].each do |edge|
      add_edge edge
    end
  end
  def add_edge edge
    @nodes[edge.first].successors << @nodes[edge.last]
  end
  def route? name1, name2
    root1 = @nodes[name1]
    root2 = @nodes[name2]
    queue1 = Queue.new
    queue2 = Queue.new
    queue1.add root1
    queue2.add root2
    until queue1.empty? and queue2.empty? do
      curr1 = queue1.remove unless queue1.empty?
      curr2 = queue2.remove unless queue2.empty?
      curr1.visited!
      curr2.visited!
      curr1.successors.each do |node|
        return true if node == root2
        queue1.add node unless node.visited?
      end
      curr2.successors.each do |node|
        return true if node == root1
        queue2.add node unless node.visited?
      end
    end
    false
  end
  def depth_first_search name
    curr = @nodes[name]
    curr.visited!
    curr.successors.each do |node|
      depth_first_search node.name unless node.visited?
    end
  end
  def breadth_first_search name
    root = @nodes[name]
    queue = Queue.new
    queue.add root
    until queue.empty? do
      curr = queue.remove
      curr.visited!
      curr.successors.each do |node|
        queue.add node unless node.visited?
      end
    end
  end
end

graph = DirectedAdjacencyList.new :nodes => 7, :edges => [[1, 2],
                                                          [1, 5],
                                                          [3, 5],
                                                          [5, 7],
                                                          [6, 7],
                                                          [7, 6],
                                                          [7, 4]] 
puts benchmark { puts graph.route? 1, 7 }
