const fs = require("fs");

BOJkey = true;

const input = fs
  .readFileSync(BOJkey ? "./ehddud1006/BOJ/4195/input.txt" : "./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .reverse();

let T = Number(input.pop());
let answer = [];
let parent;
let relation;

while (T--) {
  const N = Number(input.pop());
  let idx = 1;
  const hash = {};
  parent = Array.from({ length: 200001 }, (_, i) => i);
  relation = Array.from({ length: 200001 }, () => 1);

  for (let i = 0; i < N; i++) {
    const [a, b] = input.pop().split(" ");

    if (hash[a] === undefined) hash[a] = idx++;
    if (hash[b] === undefined) hash[b] = idx++;

    let ai = hash[a];
    let bi = hash[b];

    merge(ai, bi);
  }
}

function find(u) {
  if (u === parent[u]) return u;

  return (parent[u] = find(parent[u]));
}

function merge(u, v) {
  let U = find(u);
  let V = find(v);

  if (U === V) {
    answer.push(`${relation[U]}`);
    return;
  }

  parent[U] = V;
  relation[V] += relation[U];
  answer.push(`${relation[V]}`);
}

console.log(answer.join("\n"));
