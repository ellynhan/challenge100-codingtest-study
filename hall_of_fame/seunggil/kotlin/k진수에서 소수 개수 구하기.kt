class Solution {
    fun convert(n : Int, k: Int): String{
        var n = n
        val result = StringBuilder()
        while(n != 0){
            result.append(n % k)
            n = n / k
        }
        return result.reverse().toString()
    }

    fun isPrime(n : String) : Boolean{
        val n = n.toLong()
        if(n == 1L)
            return false
        for(i in 2 .. Math.sqrt(n.toDouble()).toInt()){
            if(n % i == 0L)
                return false
        }
        return true
    }

    fun solution(n: Int, k: Int): Int {

        val numbers = convert(n,k).split('0').filter {
            it.isNotEmpty()
        }

        var answer: Int = 0

        for(number in numbers){
            if(isPrime(number))
                answer++
        }
        return answer
    }
}