class Solution {
    public long solution(int price, int money, int count) {
        long total_price = 0;
        for(int i = 1; i<=count; i++){
            total_price += price * i;
        }
        total_price -= money;
        if (total_price < 0 ){
            return 0;
        }
        
        return total_price;
    }
}

// return Math.max(price * (count * (count + 1) / 2) - money, 0);
