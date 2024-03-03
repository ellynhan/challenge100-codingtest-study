package string.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FindPrefix {

  static class TrieNode {
    boolean word;
    TrieNode[] children;

    TrieNode() {
      children = new TrieNode[26];
      word = false;
    }

  }

  static class Trie {
    TrieNode root;

    Trie() {
      root = new TrieNode();
    }

    public void insert(String word) {
      TrieNode cur = root;
      for (int i = 0; i < word.length(); i++) {
        char c = word.charAt(i);
        if (cur.children[c - 'a'] == null) {
          cur.children[c - 'a'] = new TrieNode();
        }
        cur = cur.children[c - 'a'];
      }
      cur.word = true;
    }

    public boolean checkPrefix(String target) {
      TrieNode cur = root;
      for (char c : target.toCharArray()) {
        if (cur.children[c - 'a'] == null) {
          return false;
        }
        cur = cur.children[c - 'a'];
      }
      return true;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    Trie trie = new Trie();
    for (int i = 0; i < N; i++) {
      trie.insert(br.readLine());
    }

    int result = 0;
    for (int i = 0; i < M; i++) {
      if (trie.checkPrefix(br.readLine())) {
        result++;
      }
    }

    System.out.println(result);
  }


}
