class MinHeap {
  constructor() {
    this.heap = [];
  }

  insert(edge, value) {
    const node = { edge, value };
    this.upheap(node);
  }

  upheap(node) {
    this.heap.push(node);
    let idx = this.heap.length - 1;

    while (idx > 0) {
      let parentIdx = (idx - 1) >> 1;
      if (this.heap[parentIdx].value <= node.value) break;

      this.heap[idx] = this.heap[parentIdx];
      idx = parentIdx;
    }
    this.heap[idx] = node;
  }

  remove() {
    if (this.heap.length == 0) return undefined;
    if (this.heap.length == 1) return this.heap.pop();
    const res = this.heap[0];
    const node = this.heap.pop();
    this.downheap(node);

    return res;
  }

  downheap(node) {
    let len = this.heap.length >> 1;
    let idx = 0;

    while (idx < len) {
      let left = (idx << 1) + 1;
      let right = left + 1;
      let small = left;

      if (
        right < this.heap.length &&
        this.heap[left].value > this.heap[right].value
      )
        small = right;

      if (this.heap[small].value >= node.value) break;
      this.heap[idx] = this.heap[small];
      idx = small;
    }

    this.heap[idx] = node;
  }
}

const fs = require("fs");

BOJkey = false;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/11779/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const [V] = input.pop();
const [E] = input.pop();

const INF = Number.MAX_SAFE_INTEGER;
const adj = Array.from({ length: V + 1 }, () => []);
const d = Array.from({ length: V + 1 }, () => INF);
const pre = Array.from({ length: V + 1 }, () => 0);

for (let i = 0; i < E; i++) {
  const [u, v, w] = input.pop();

  adj[u].push([v, w]);
}

const [st, end] = input.pop();

d[st] = 0;
const pq = new MinHeap();
pq.insert(st, d[st]);

while (pq.heap.length) {
  const { edge: node, value: dist } = pq.remove();

  if (d[node] != dist) continue;

  for (const [nextNode, nextDist] of adj[node]) {
    if (d[nextNode] <= d[node] + nextDist) continue;
    d[nextNode] = d[node] + nextDist;
    pre[nextNode] = node;
    pq.insert(nextNode, d[nextNode]);
  }
}

let currentNode = end;
let answer = "";
let count = 1;
while (currentNode !== st) {
  answer = `${currentNode} ` + answer;
  currentNode = pre[currentNode];
  count++;
}

answer = `${st} ` + answer;

console.log(d[end]);
console.log(count);
console.log(answer);
