package 프린터큐_1966;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Main {

  static int numberOfTestCase, numberOfDocuments, targetIndex, answer;

  static Document targetDocument;

  static List<Document> documents = new ArrayList<>();

  public static class Document {

    private int index;
    private int importance;

    public Document(int index, int importance) {
      this.index = index;
      this.importance = importance;
    }

    public int getIndex() {
      return index;
    }

    public int getImportance() {
      return importance;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    numberOfTestCase = Integer.parseInt(br.readLine());
    for (int i = 0; i < numberOfTestCase; i++) {
      input(br);
      solve();
      print();
      documents.clear();
    }
  }

  private static void input(BufferedReader br) throws IOException {
    String[] s1 = br.readLine().split(" ");
    numberOfDocuments = Integer.parseInt(s1[0]);
    targetIndex = Integer.parseInt(s1[1]);
    String[] s2 = br.readLine().split(" ");
    for (int j = 0; j < numberOfDocuments; j++) {
      Document newDocument = new Document(j, Integer.parseInt(s2[j]));
      documents.add(newDocument);
      if (j == targetIndex) {
        targetDocument = newDocument;
      }
    }
  }

  private static void solve() {
    answer = 1;
    while (true) {
      Document document = documents.get(0);
      Optional<Document> find = documents
          .subList(1, documents.size())
          .stream()
          .filter(d -> d.getImportance() > document.getImportance())
          .findFirst();
      if (find.isEmpty()) {
        if (document.getIndex() == targetIndex) {
          break;
        } else {
          answer++;
          documents.remove(0);
        }
      } else {
        documents.add(document);
        documents.remove(0);
      }
    }
  }

  private static void print() {
    System.out.println(answer);
  }
}
