class Solution {
    public long solution(int w, int h) {
        long answer = 1;
        long wl=(long)w;
        long hl=(long)h;
        answer=(wl*hl)-((wl+hl)-gcd(wl,hl));
        return answer;
    }
    private long gcd(long w,long h){
        if(h==0){
            return w;
        }
        return gcd(h,w%h);
    }
}
