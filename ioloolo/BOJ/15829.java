import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static int L;
	static char[] chars;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		L = Integer.parseInt(reader.readLine());
		chars = reader.readLine().toCharArray();
	}

	static void solve() throws IOException {
		BigInteger sum = BigInteger.ZERO;

		for (int i = 0; i < L; ++i) {
			sum = sum.add(BigInteger.valueOf(chars[i] - 96).multiply(BigInteger.valueOf(31).pow(i)));
		}

		writer.write(sum.remainder(BigInteger.valueOf(1234567891)).toString());
	}
}
