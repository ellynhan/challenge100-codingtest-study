import java.io.*;
class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        if(Integer.parseInt(input) % 2 == 0){
            System.out.println("even");
        }else if(Integer.parseInt(input) % 2 != 0){
            System.out.println("odd");
        }
    }
}

/*
* 문자 → 정수 : Integer.parseInt("문자열");

정수 → 문자 : Integer.toString(10);

그 외) Double.parseDouble("10.5");

데이터 타입들끼리의 형변화

```java
int a = (int)10.5;
float f = 10.5f;
double d = 10.6d;
long l = 1020549589348967436L;

//(int)실수값
int i_num = 10;

double d_num = (double)i_num; //Int -> Double
float f_num = (float)i_num; //Int -> Float
```
* */