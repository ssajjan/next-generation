def benchmark
  b = Time.now
  yield
  a = Time.now
  a - b
end

class LinkedList
  attr_reader :head
  Node = Struct.new :value, :next
  def initialize *nodes
    @head = Node.new
    nodes.each do |value|
      push value
    end
  end
  def partition val
    runner = @head
    while runner and runner.next.value do
      if runner.next.value < val
        push runner.next.value
        delete runner.next
      else
        runner = runner.next
      end
    end
  end
  def get idx, curr=@head,count=0
    return -1 unless curr
    return curr if count == idx
    get idx, curr.next, count + 1  
  end
  def delete node
    destroy = node.next.dup
    node.next = destroy.next
    node.value = destroy.value
  end
  def push value
    new_node = Node.new(value)
    new_node.next = @head.dup
    @head = new_node
  end
  def remove_dups curr=@head
    runner = curr
    while runner and runner.next do
      if runner.next.value == curr.value
        runner.next = runner.next.next
      else
        runner = runner.next
      end
    end
    curr.next ? remove_dups(curr.next) : return
  end
  def kth_to_last(curr=@head, k)
    loop do
      runner = curr
      k.times do
        runner = runner.next
      end
      break curr unless runner
      curr = curr.next
    end
  end
  def to_s list=@head, msg=""
    return msg[0..-4] if list.value.nil?
    to_s list.next, msg<<"#{list.value} -> "
  end
end
