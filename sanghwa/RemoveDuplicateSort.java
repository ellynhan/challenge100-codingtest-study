import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class RemoveDuplicateSort {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		Set<Integer> set = new HashSet<>();
		while (st.hasMoreTokens()) {
			set.add(Integer.parseInt(st.nextToken()));
		}

		int[] arr = new int[set.size()];
		int idx = 0;
		for (int x : set)
			arr[idx++] = x;

		Arrays.sort(arr);

		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for (int i = arr.length - 1; i >= 0; i--) {
			sb.append(arr[i]);
			if (i != 0)
				sb.append(", ");
		}
		sb.append("]");

		System.out.println(sb);
	}
}
