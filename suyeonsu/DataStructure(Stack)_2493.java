import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
	static class Node {
		int h, idx;

		Node(int h, int idx) {
			this.h = h;
			this.idx = idx;
		}
	}
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		Stack<Node> stack = new Stack<>();
		StringBuilder answer = new StringBuilder();
		for(int i=1; i<=n; i++) {
			int h = Integer.parseInt(st.nextToken());
			while(!stack.isEmpty()) {
				if(stack.peek().h >= h) {
					answer.append(stack.peek().idx + " ");
					break;
				}
				stack.pop();
			}
			if(stack.isEmpty()) {
				answer.append("0 ");
			}
			stack.push(new Node(h, i));
		}
		System.out.println(answer);
	}
}
