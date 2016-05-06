class Queue
  QueueNode = Struct.new :value, :next
  def initialize
    @head = nil
    @last = nil
  end
  def add value
    new_node = QueueNode.new value
    @last.next = new_node if @last
    @last = new_node
    @head = @last unless @head
  end
  def remove 
    raise "Queue empty" if empty?
    node = @head
    @head = @head.next
    @last = @head unless @head
    node.value
  end
  def peek
    raise "Queue empty" if empty?
    @head.value
  end
  def empty?
    !@head
  end
end
