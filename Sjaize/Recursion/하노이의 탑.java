import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] solution(int n) {
        Trace trace = NblockFromAtoB(1,3,n);
        return trace.toArray();
    }
    
    private Trace NblockFromAtoB(int A, int B, int n) {
        if (n == 1) return new Trace(A,B);
        int C = 6 - A - B;
        return NblockFromAtoB(A,C,n-1)
                .add(NblockFromAtoB(A,B,1))
                .add(NblockFromAtoB(C,B,n-1));
    }
    
    private static class Trace {
        private List<int[]> trace = new ArrayList<>();
        Trace(int A, int B) {
            trace.add(new int[] {A,B});
        }
        private Trace add(Trace other) {
            trace.addAll(other.trace);
            return this;
        }
        private int[][] toArray() {
            return trace.toArray(new int[0][]);
        }
    }
}
