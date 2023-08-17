import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static StringTokenizer tokenizer;

	static int A;
	static int B;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());

		A = Integer.parseInt(tokenizer.nextToken());
		B = Integer.parseInt(tokenizer.nextToken());
	}

	static void solve() throws IOException {
		int gcd = BigInteger.valueOf(A).gcd(BigInteger.valueOf(B)).intValue();
		int lcm = A*B / gcd;

		writer.write(Integer.toString(gcd));
		writer.newLine();
		writer.write(Integer.toString(lcm));
	}
}
