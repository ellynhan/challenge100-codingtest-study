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
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/1753/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const [V, E] = input.pop();
const st = input.pop().pop();

const INF = Number.MAX_SAFE_INTEGER;
const adj = Array.from({ length: V + 1 }, () => []);
const d = Array.from({ length: V + 1 }, () => INF);

for (let i = 0; i < E; i++) {
  const [u, v, w] = input.pop();

  adj[u].push([w, v]);
}

d[st] = 0;
const pq = new MinHeap();
pq.insert(st, d[st]);

while (pq.heap.length) {
  const { edge: node, value: dist } = pq.remove();

  if (d[node] != dist) continue;

  for (const [nextDist, nextNode] of adj[node]) {
    if (d[nextNode] <= d[node] + nextDist) continue;
    d[nextNode] = d[node] + nextDist;
    pq.insert(nextNode, d[nextNode]);
  }
}

const answer = [];

for (let i = 1; i <= V; i++) {
  if (d[i] === INF) answer.push("INF");
  else answer.push(d[i]);
}

console.log(answer.join("\n"));
