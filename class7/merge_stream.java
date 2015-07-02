/* Merge the sorted data stream into one large sorted data. */
List<Integer> merge(AStream[] dataLists) {
    if (dataLists == null || dataLists.length == 0)
        return null;

    // 1. prepare the queue. Build the heap for first element of the queue.
    // Note that the QElem is comparable for the first element.
    PriorityQueue<QElem> priQ = new PriorityQueue<QElem>();
    for (AStream data : dataLists) {
        if (data == null) {
            continue;
        }
        QElem qElem = new QElem(data);
        priQ.add(qElem);    
    }

    // 2. heap is ready. Pull out the data one by one from the priority
    // queue. SUPER_LARGE is the marker of end of stream.
    List<Integer> merged = new ArrayList<Integer>();
    do {
        QElem qElem = priQ.poll();
        Integer data = qElem.stream.curData();
        if (data == SUPER_LARGE) {
            continue;
        }
        // still a valid data, put the element back.
        merged.add(data);
        qElem.stream.readNext();
        priQ.add(qElem);
    } while (!priQ.isEmpty());
    return merged;
}

