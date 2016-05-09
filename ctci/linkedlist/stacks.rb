class Stack
  Node = Struct.new :value, :next
  def initialize
    @head = nil
  end
  def push value
    node = Node.new value
    node.next = @head
    @head = node
  end
  def pop
    raise "stack empty" if empty?
    result = @head
    @head = @head.next
    result
  end
  def peek
    raise "stack empty" if empty?
    @head.value 
  end
  def empty?
    !@head
  end
end
