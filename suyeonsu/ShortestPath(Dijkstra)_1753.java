import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

		static class Node {
				int idx;
				int cost;
		
				public Node(int idx, int cost) {
						this.idx = idx;
						this.cost = cost;
				}
		}
		
		static ArrayList<Node>[] graph;
		static boolean[] visited;
		static int[] distance;
		static final int INF = Integer.MAX_VALUE;
		
		public static void main(String[] args) throws IOException {
				BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				StringTokenizer st = new StringTokenizer(br.readLine());
				int V = Integer.parseInt(st.nextToken());
				int E = Integer.parseInt(st.nextToken());
				int k = Integer.parseInt(br.readLine());
				graph = new ArrayList[V+1];
				visited = new boolean[V+1];
				distance = new int[V+1];
				for(int i=1; i<=V; i++) {
						graph[i] = new ArrayList<>();
				}
				for(int i=0; i<E; i++) {
						st = new StringTokenizer(br.readLine());
						int u = Integer.parseInt(st.nextToken());
						int v = Integer.parseInt(st.nextToken());
						int w = Integer.parseInt(st.nextToken());
						graph[u].add(new Node(v, w));
				}
				Arrays.fill(distance, INF);
				
				dijkstra(k);
				for(int i=1; i<=V; i++) {
						System.out.println(distance[i] != INF ? distance[i] : "INF");
				}
		}
	
		private static void dijkstra(int srt) {
				PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
				
				pq.offer(new Node(srt, 0));
				distance[srt] = 0;
				while(!pq.isEmpty()) {
						Node cur = pq.poll();
						visited[cur.idx] = true;
						if(distance[cur.idx] < cur.cost) continue;
						for(Node nxt: graph[cur.idx]) {
								int i = nxt.idx;
								int d = distance[cur.idx] + nxt.cost;
								if(!visited[i] && d < distance[i]) {
									distance[i] = d;
									pq.offer(new Node(i, d));
								}
						}
				}
		}

}
