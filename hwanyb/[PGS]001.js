function solution(babbling) {
    let answer = 0;
    const can = ["aya", "ye", "woo", "ma"];

    for (let i in babbling) {
      let init = babbling[i];

      for (let j in can) {
        if (babbling[i].includes(can[j])) {
          init = init.replace(can[j], "X");
        }
      }

      init = init.replaceAll("X", "");
      if (init.length === 0) {
        answer += 1;
      }
    }
    return answer;
  }