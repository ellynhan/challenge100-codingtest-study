function solution(age) {
    const map = {
        0: "a",
        1: "b",
        2: "c",
        3: "d",
        4: "e",
        5: "f",
        6: "g",
        7: "h",
        8: "i",
        9: "j"
    };

    return [...age.toString()].map(i => map[i]).join("");
}

// 간단한 풀이
function solution(age) {
    return age
        .toString()
        .split("")
        .map((v) => "abcdefghij"[v])
        .join("");
}