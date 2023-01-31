// 위험도가 높은 환자순으로
// 위험도가 가장높고 가장앞에 있는 사람이 진료. 보다큰!

// N명 M번째는 몇번째에 진료받는가

//로직.
//  1. 큐 초기화
//  2. 배열 sorting
//  3. max 값만 방출
//  예외. 숫자값이 같을 수 있다


// max값을 쉽게 초기화해서 구하는 방법도 시도해보기
import java.util.*;

class Person{
    int idx;
    int prior;
    public Person(int idx, int prior){
        this.idx = idx;
        this.prior = prior;
    }
}

class Main{

    public static int sol(int n, int m, int[] t){
        int ans = 0;
        Queue<Person> q = new LinkedList<>();

        for(int i=0; i<n; i++){
            q.offer(new Person(i,t[i]));
        }

        Person tmp;
        int cnt = 0;
        while(!q.isEmpty()){
            tmp = q.poll();
            for(Person x:q){
                if(x.prior > tmp.prior){
                    q.offer(tmp);
                    tmp = null;
                    break;
                }
            }
            if(tmp != null){
                if(tmp.idx == m) {cnt++; return cnt;}
                else{cnt++;}
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }

        System.out.print(sol(n,m,t));
    }
}