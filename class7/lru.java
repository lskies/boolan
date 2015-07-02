Class LRU {   
    private int size;
    private HashMap<Object, Node> cache;
    private DoubleLinkedList list;
    private int count;

    public LRU(int size) {
        list = new DoubleLinkedList();
        count = 0;
        this.size = size;
        cache = new HashMap<Object, Node>();
    }
    public Object get(Object key) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            list.movefront(node);
            return node.value;
        }
        return null;
    }

    public void set(Object key, Object value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value;
        } else {
            Node node = new Node(key, value);
            list.add(node);
            cache.put(key, node);
            if (count < size) {
                count++;
            } else {
                cache.remove(list.getTail().key);
                list.removeLast();
            }
        }
    }

