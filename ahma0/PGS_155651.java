
import java.util.*;

public class Solution {

    private class RoomTime {
        int start, end;

        public RoomTime(String startTime, String endTime) {
            start = Integer.parseInt(startTime.split(":")[0]) * 60 + Integer.parseInt(startTime.split(":")[1]);
            end = Integer.parseInt(endTime.split(":")[0]) * 60 + Integer.parseInt(endTime.split(":")[1]) + 10;
        }
    }

    public int solution(String[][] book_time) {
        PriorityQueue<Integer> rooms = new PriorityQueue<>();
        PriorityQueue<RoomTime> priorityQueue = new PriorityQueue<>((o1, o2) -> {
            if (o1.start == o2.start) {
                return o1.end - o2.end;
            }
            return o1.start - o2.start;
        });

        for(int i = 0; i < book_time.length; i++)
            priorityQueue.add(new RoomTime(book_time[i][0], book_time[i][1]));

        for(int i = 0; i < book_time.length; i++) {
            RoomTime room = priorityQueue.poll();

            if(rooms.isEmpty()) {
                rooms.add(room.end);
                continue;
            }

            if(room.start >= rooms.peek())
                rooms.remove();

            rooms.add(room.end);
        }

        return rooms.size();
    }

}