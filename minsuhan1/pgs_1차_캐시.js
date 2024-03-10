function solution(cacheSize, cities) {
    // LRU: 가장 오랫동안 참조되지 않은 페이지를 교체
    let answer = 0;
    cache = [];
    
    if(cacheSize === 0) {
        answer = 5 * cities.length;
    } else {
        cities.forEach(city => {
            city = city.toLowerCase();

            if (cache.includes(city)) {
                answer += 1;
                // cache hit인 경우 가장 최근에 참조된것으로 처리
                cache = cache.filter(c => c !== city)
                cache.push(city)
            } else {
                answer += 5;
                if (cache.length < cacheSize) {
                    cache.push(city);
                } else {
                    cache.shift();
                    cache.push(city);
                }
            }
        });
    }
    
    return answer;
}
