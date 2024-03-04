function solution(n, arr1, arr2) {
    let answer = [];
    const bAns = arr1.map((num, idx) => (num | arr2[idx]).toString(2).padStart(n, "0"));
    answer = bAns.map(bStr => bStr.replaceAll('0', ' ').replaceAll('1', '#'))
    return answer;
}
