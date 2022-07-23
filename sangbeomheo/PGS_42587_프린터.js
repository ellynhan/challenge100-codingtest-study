/*

프로그래머스 / 프린터 / 레벨 2
https://programmers.co.kr/learn/courses/30/lessons/42587

< 소요 시간 >
2시간

*/

class Queue {
  constructor() {
    this.queue = [];
    this.front = 0;
    this.rear = 0;
  }

  enqueue(value) {
    this.queue[this.rear++] = value;
  }

  dequeue() {
    const value = this.queue[this.front];
    this.front++;
    return value;
  }

  peek() {
    return this.queue[this.front];
  }
}

function solution(priorities, location) {
  const printQueue = new Queue();

  priorities.forEach((priority, index) => {
    printQueue.enqueue({ priority, order: index });
  });

  priorities.sort((a, b) => b - a);

  let printCount = 0;

  while (true) {
    const frontValue = printQueue.peek();
    const maxPriority = priorities[printCount];

    if (frontValue.priority < maxPriority) {
      printQueue.enqueue(printQueue.dequeue());
    } else {
      const printedValue = printQueue.dequeue();
      printCount++;
      if (printedValue.order === location) return printCount;
    }
  }
}
