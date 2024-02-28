/*

프로그래머스 / [3차] 자동완성 / 레벨 4
https://school.programmers.co.kr/learn/courses/30/lessons/17685

< 소요 시간 >
39분

<프로그래밍 계획>
  1. Trie 구현

  2. words를 순회하면서 word를 Trie에 insert
    - 선택이 4보다 크면 4로 나눈 나머지가 점수
    - 프로퍼티로 해당 node가 몇 번 거처갔는지 count 체크

  3. words를 순회하면서 word의 count 값 체크
    - count가 1이면 종료 후 몇번 거쳐왔는지 리턴
*/

function solution(words) {
  const trie = new Trie();

  words.forEach(word => trie.insert(word));

  const lengths = words.map(word => trie.getLengthForSearch(word));

  return lengths.reduce((sum, length) => sum + length, 0);
}

class Node {
  constructor(value = '') {
    this.value = value;
    this.count = 0;
    this.children = new Map();
  }
}

class Trie {
  constructor() {
    this.root = new Node();
  }

  insert(string) {
    let current = this.root;

    for (const char of string) {
      if (!current.children.has(char)) {
        current.children.set(char, new Node(current.value + char));
      }
      current = current.children.get(char);
      current.count++;
    }
  }

  getLengthForSearch(string) {
    let current = this.root;
    let count = 0;

    for (const char of string) {
      count++;
      const node = current.children.get(char);

      if (node.count === 1) break;

      current = current.children.get(char);
    }

    return count;
  }
}
