const fs = require("fs");

BOJkey = true;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/1197/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map(Number))
  .reverse();

const [V, E] = input.pop();
const parent = Array.from({ length: V + 1 }, (_, i) => i);
let answer = 0;
let findMstVertex = 0;

input.sort((a, b) => b[2] - a[2]);

for (let i = 0; i < E; i++) {
  const [a, b, dist] = input.pop();

  if (!isDiffGroup(a, b)) continue;

  answer += dist;
  findMstVertex++;
  if (findMstVertex === V - 1) break;
}

function find(u) {
  if (u == parent[u]) {
    return u;
  }
  return (parent[u] = find(parent[u]));
}

function isDiffGroup(u, v) {
  const U = find(u);
  const V = find(v);
  if (U === V) return false;

  parent[U] = V;

  return true;
}

console.log(answer);
