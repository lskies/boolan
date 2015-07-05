public class BlockingQueueImpl<T> implements BlockingQueue<T>
{
  private final Queue<T> q = new LinkedList<T>();
  private final int maxSize;
  private final Object mutex = new Object();
 
  public BlockingQueueImpl(int maxSize) {
    if (maxSize <= 0)
      throw new IllegalArgumentException("maxSize=" + maxSize);
    this.maxSize = maxSize;
  }
 
  public T take() throws InterruptedException {
    synchronized (mutex) {
      while (q.isEmpty()) mutex.wait();
      mutex.notifyAll(); // Wake up threads waiting to put (or take)
      return q.remove();
    }
  }
 
  public void put(T obj) throws InterruptedException {
    synchronized (mutex) {
      while (q.size() >= maxSize) mutex.wait();
      mutex.notifyAll(); // Wake up threads waiting to take (or put)
      q.add(obj);
    }
  }
}
