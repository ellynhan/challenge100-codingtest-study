/*

프로그래머스 / 배상 비용 최소화 / 레벨 2
https://programmers.co.kr/learn/courses/30/lessons/91086

< 소요 시간 >
2시간
 
< 프로그래밍 계획 >

- 1차 시도 - 효율성 테스트 실패
  1. 작업량 전체 합계보다 no가 같거나 크다면 => return 0
  2. no 만큼 루프
      - 내림차순 정렬
      - 제일 큰 작업량이 0이면 루프 종료 => return 0
      - 제일 큰 작업량이 0보다 크면 => 작업량--, no--
  3. 배상 비용 계산 후 리턴

- 2차 시도 - 우선순위 큐
  1. 작업량 전체 합계보다 no가 같거나 크다면 => return 0
  2. no 만큼 루프
      - 우선순위 큐에 작업량 enqueue
      - 큐에서 dequeue하고 dequeue한 값의 -1을 enqueue
  3. 배상 비용 계산 후 리턴

*/

// 2차 시도 - 통과
class MaxHeap {
  constructor() {
    this.heap = [null];
  }

  getParent(current) {
    return Math.floor(current / 2);
  }

  isEmpty() {
    return this.heap.length === 1;
  }

  isOnlyRoot() {
    return this.heap.length === 2;
  }

  enqueue(value) {
    this.heap.push(value);

    let current = this.heap.length - 1;
    let parent = this.getParent(current);

    while (parent && this.heap[parent] < value) {
      [this.heap[current], this.heap[parent]] = [
        this.heap[parent],
        this.heap[current],
      ];
      current = parent;
      parent = this.getParent(current);
    }
  }

  dequeue() {
    if (this.isEmpty()) return 0;
    if (this.isOnlyRoot()) return this.heap.pop();

    const returnValue = this.heap[1];
    this.heap[1] = this.heap.pop();

    let [current, left, right] = [1, 2, 3];

    while (
      this.heap[current] < this.heap[left] ||
      this.heap[current] < this.heap[right]
    ) {
      if (this.heap[left] < this.heap[right]) {
        [this.heap[current], this.heap[right]] = [
          this.heap[right],
          this.heap[current],
        ];
        current = right;
      } else {
        [this.heap[current], this.heap[left]] = [
          this.heap[left],
          this.heap[current],
        ];
        current = left;
      }

      left = current * 2;
      right = current * 2 + 1;
    }

    return returnValue;
  }
}

function solution(no, works) {
  if (no >= works.reduce((sum, work) => sum + work)) return 0;

  const worksHeap = new MaxHeap();
  works.forEach((work) => worksHeap.enqueue(work));

  while (no > 0) {
    worksHeap.enqueue(worksHeap.dequeue() - 1);
    no--;
  }

  return worksHeap.heap.reduce((sqrtSum, work) => sqrtSum + work * work, 0);
}

/*

// 1차 시도 - 효율성 테스트 실패
function solution(no, works) {
  if (no >= works.reduce((a, c) => a + c)) return 0;

  while (no > 0) {
    works.sort((a, b) => b - a);
    if (!works[0]) return 0;
    works[0]--;
    no--;
  }

  return works.reduce((sum, work) => sum + work * work, 0);
}

*/
