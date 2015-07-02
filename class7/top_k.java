public static int[] findTopN(int[] values, int k) {
    int[] res = new int[n];
    int size = values.length;
    PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(n);
    for (int i =0; i < size; i++) {
      if (minHeap.size() < k) {
        minHeap.add(values[i]);
      }
      else {
        if (minHeap.peek() < values[i]) {
          minHeap.poll();
          minHeap.add(values[i]);
        }
      }
    }

    int i =0;
    while (!minHeap.isEmpty())
    {
        res[i++] = minHeap.poll();
    }
    return res;
}

}
