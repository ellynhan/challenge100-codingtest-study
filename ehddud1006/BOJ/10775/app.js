const fs = require("fs");

BOJkey = true;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/10775/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const [G] = input.pop();
const [P] = input.pop();
const parent = Array.from({ length: G + 1 }, (_, i) => i);
let answer = 0;

for (let i = 0; i < P; i++) {
  const [gi] = input.pop();

  const docking = find(gi);

  if (docking !== 0) {
    merge(docking, docking - 1);
    answer++;
  } else break;
}

function find(u) {
  if (u == parent[u]) {
    return u;
  }
  return (parent[u] = find(parent[u]));
}

function merge(u, v) {
  const U = find(u);
  const V = find(v);
  if (U === V) return;

  parent[U] = V;
}

console.log(answer);
