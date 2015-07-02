import java.util.*;


public class TopoSort {

  public static void main(String[] args) {
    int n = 4;
    int m = 5;
    String[] inputs = new String[m];
    inputs[0] = "bc";
    inputs[1] = "dc";
    inputs[2] = "ad";
    inputs[3] = "bd";
    inputs[4] = "ba";
    char[] letters = {'a', 'b', 'c' , 'd'};

    // init graph with n nodes
    Map<Character, List<Character>> graph = new HashMap<Character, List<Character>>();
    Map<Character, Integer> indegs = new HashMap<Character, Integer>();
    for (int i=0; i<n; i++) {
      graph.put(letters[i], new ArrayList<Character>(n));
      indegs.put(letters[i], 0);
    }

    // build edges
    for (int j=0; j<m; j++) {
      char from = inputs[j].charAt(0);
      char to = inputs[j].charAt(1);
      graph.get(from).add(to);
      indegs.put(to, indegs.get(to) + 1);
    }

    List<Character> res = topoSort(graph, indegs);
    for (char c: res) {
      System.out.print(c + "->");
    }
  }

  private static List<Character> topoSort(Map<Character, List<Character>> graph,
                                          Map<Character, Integer> indegs) {
    List<Character> res = new ArrayList<Character>();
    int n = indegs.size();
    boolean[] visited = new boolean[256];
    Queue<Character> queue = new LinkedList<Character>();

    // enqueue 0-in-degree nodes
    for (Map.Entry<Character, Integer> entry: indegs.entrySet()) {
      if (entry.getValue() == 0)
        queue.add(entry.getKey());
    }

    // bfs
    while (!queue.isEmpty()) {
      Character node = queue.poll();
      res.add(node);
      // mark as visited
      visited[node] = true;
      // update its neighbors and enqueue 0-in-degree ones
      for (char neighbour : graph.get(node)) {
        if (visited[neighbour]) { // a cycle detected
          break;
        }
        indegs.put(neighbour, indegs.get(neighbour)-1);
        if (indegs.get(neighbour) == 0) {
          queue.add(neighbour);
        }
      }
      // can delete that node from graph, but not not necessary
    }
    return res;
  }
}

