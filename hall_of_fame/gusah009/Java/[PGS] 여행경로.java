import java.util.*;

class Ticket implements Comparable {

  String dst;
  boolean isUsed;

  public Ticket(String dst, boolean isUsed) {
    this.dst = dst;
    this.isUsed = isUsed;
  }

  @Override
  public int compareTo(Object o) {
    return dst.compareTo(((Ticket) o).dst);
  }
}

class Solution {

  private static Stack<String> answer = new Stack<>();
  private static Map<String, List<Ticket>> path = new TreeMap<>();
  private static int ticketCount;

  public String[] solution(String[][] tickets) {
    ticketCount = tickets.length;

    initPath(tickets);

    dfs("ICN");

    return answer.toArray(new String[answer.size()]);
  }

  private boolean dfs(String src) {
    answer.add(src);

    if (answer.size() == ticketCount + 1) {
      return true;
    }

    List<Ticket> tickets = path.get(src);
    if (tickets != null) {
      for (Ticket ticket : tickets) {
        if (!ticket.isUsed) {
          ticket.isUsed = true;
          if (dfs(ticket.dst)) {
            return true;
          }
          ticket.isUsed = false;
        }
      }
    }
    answer.pop();
    return false;
  }

  private void initPath(String[][] tickets) {
    for (String[] ticket : tickets) {
      String src = ticket[0];
      String dst = ticket[1];

      List<Ticket> dstList = path.get(src);
      if (dstList == null) {
        dstList = new ArrayList<>();
        path.put(src, dstList);
      }
      dstList.add(new Ticket(dst, false));
    }

    path.forEach((src, dstList) -> {
      dstList.sort(Comparator.naturalOrder());
    });
  }
}