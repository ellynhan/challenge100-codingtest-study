import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2)-> o1[0] == o2[0] ? o1[1]-o2[1] : o1[0]-o2[0]);
		StringBuilder answer = new StringBuilder();
		for(int i=0; i<n; i++) {
			int x = Integer.parseInt(br.readLine());		
			if(x == 0) {
				if(pq.isEmpty()) answer.append('0');
				else answer.append(pq.poll()[1]);
				answer.append('\n');
			} else{
				pq.offer(new int[] {Math.abs(x), x});
			}
		}
		System.out.println(answer);
	}

}
