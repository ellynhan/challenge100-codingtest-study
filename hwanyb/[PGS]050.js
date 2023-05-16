function solution(n) {
    const arr = Array.from({ length: n }, (_, i) => i + 1);
    let count = 0;

    for (let i = 0; i < arr.length; i++) {
        if (n % arr[i] === 0) {
            count += 1;
        }
    }
    return count;
}