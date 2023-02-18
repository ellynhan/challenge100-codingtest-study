package PNU_Data_Structure.nanobot;

import java.awt.SystemTray;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws IOException {
    Scanner scanner = new Scanner(System.in);
    Nanobot nanobot = new Nanobot();
    nanobot.run(scanner);
    nanobot.print();

    scanner.close();
  }
}
