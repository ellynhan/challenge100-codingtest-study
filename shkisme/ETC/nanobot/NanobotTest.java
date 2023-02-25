package PNU_Data_Structure;

import static java.nio.file.Files.newBufferedReader;

import PNU_Data_Structure.nanobot.Nanobot;
import PNU_Data_Structure.nanobot.Nanobot.Coordinate;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;
import java.util.Scanner;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class NanobotTest {

  static int start = 1;
  /**
   * @end : 평가 데이터의 총 개수
   */
  static int end = 10, score = 10;
  /**
   * @time : 제한시간(초)
   */
  static int time = 1;
  /**
   * @problemName : 문제 이름
   */
  static String problemName = "nanobot";

  @Test
  @DisplayName("나노 로봇 평가 데이터 테스트")
  public void nanobotEvalTest() throws IOException {
    for (int i = start; i <= end; i++) {
      // given
      File inputFile = new File(
          "src/main/resources/PNU_Data_Structure/" + problemName + "/Eval_Data/" + i
              + ".inp"); // 문제 파일
      File answerFile = new File(
          "src/main/resources/PNU_Data_Structure/" + problemName + "/Eval_Data/" + i
              + ".out"); // 답안 파일
      File writeFile = new File(
          "src/main/resources/My_Answer/" + problemName + "/answer" + i
              + ".out"); // 답안을 쓸 파일

      FileWriter fileWriter = new FileWriter(writeFile);
      BufferedWriter writer = new BufferedWriter(fileWriter);
      Scanner scanner = new Scanner(inputFile.getAbsoluteFile(), StandardCharsets.UTF_8);
      /**
       * 실행 할 문제 클래스의 인스턴스 생성
       */
      Nanobot nanobot = new Nanobot();

      // when
      try {
        long start = System.currentTimeMillis();
        /**
         * run 메서드 실행
         */
        nanobot.run(scanner);
        start = 0;
        long end = System.currentTimeMillis();
        if ((end - start) > time * 1000L) {
          score--;
          throw new Exception("[TIME OUT] 제한시간을 초과했습니다.");
        }
        System.out.printf("[CORRECT] %d 번 [TIME]: %2d ms\n", i, (end - start));
      } catch (Exception e) {
        e.printStackTrace();
      }

      /**
       * 정답을 파일에 쓰는 함수
       * @parameter : writer
       * @parameters : 정답에 관여하는 변수들
       */
      write(writer, nanobot.getMap(), nanobot.getCoordinate(), nanobot.getNumber());

      // then
      BufferedReader answer = newBufferedReader(answerFile.toPath());
      BufferedReader write = newBufferedReader(writeFile.toPath());
      String line;
      try {
        while ((line = answer.readLine()) != null) {
          if (!line.equals(write.readLine())) {
            score--;
            throw new Exception("[WRONG Answer] 틀렸습니다.");
          }
        }
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
    System.out.println("총점 : " + score + " 점 (만점 : " + end + "점)");
  }

  /**
   * 정답 값을 찾아 파일에 입력
   */
  private void write(BufferedWriter writer, Map<Integer, Coordinate> map, Integer[] coordinate,
      int number) throws IOException {
    Optional<Entry<Integer, Coordinate>> first = map.entrySet()
        .stream()
        .filter(
            integerCoordinateEntry -> integerCoordinateEntry.getValue().getX() == coordinate[0]
                && integerCoordinateEntry.getValue().getY() == coordinate[1])
        .findFirst();
    writer.write(first.get().getKey() + "\n");
    writer.write(map.get(number).getX() + " " + map.get(number).getY() + "\n");
    writer.flush();
  }
}
