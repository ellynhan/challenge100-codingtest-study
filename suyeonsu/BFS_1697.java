import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int N, K;
	static int answer;
	
	static class Location {
		int x;
		int time;
		
		public Location(int x, int time) {
			this.x = x;
			this.time = time;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		HashSet<Integer> visited = new HashSet<>();
		Queue<Location> q = new LinkedList<>();
		
		q.offer(new Location(N, 0));
		visited.add(N);
		while(!q.isEmpty()) {
			Location cur = q.poll();
			if(cur.x == K) {
				answer = cur.time;
				break;
			}
			for(int dx : new int[] {cur.x, 1, -1}) {
				int nx = cur.x+dx;
				if(0 <= nx && nx <= 100000 && !visited.contains(nx)) {
					q.offer(new Location(nx, cur.time+1));
					visited.add(nx);
				}
			}
		}
		System.out.println(answer);
	}

}
