function solution(my_string) {
    const vowel = ['a', 'e', 'i', 'o', 'u'];
    return [...my_string].filter(i => !vowel.includes(i)).join('');
}


// 정규식 표현
function solution(my_string) {
    return my_string.replace(/[aeiou]/g, '');
}