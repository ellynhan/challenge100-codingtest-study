const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const node = +input[0];
const array = input.slice(2).map((i) => i.split(" ").map((v) => +v));

let [graph, visited] = [[], []];
for (let i = 0; i < node + 1; i++) {
  graph.push([]);
  visited.push(0);
}

array.forEach((arr) => {
  graph[arr[0]].push(arr[1]);
  graph[arr[1]].push(arr[0]);
});

// 너비 우선 탐색
function bfs(graph, start, visited) {
  let result = [];
  let queue = [start];
  visited[start] = 1;

  while (queue.length !== 0) {
    const v = queue.shift();
    result.push(v);
    graph[v].forEach((i) => {
      if (!visited[i]) {
        queue.push(i);
        visited[i] = 1;
      }
    });
  }
  return result.length - 1;
}

console.log(bfs(graph, 1, visited));

/* 깊이 우선 탐색
let result = [];
function dfs(graph, start, visited) {
  visited[start] = 1;
  result.push(start);
  graph[start].forEach((i) => {
    if (!visited[i]) return dfs(graph, i, visited);
  });
}

dfs(graph, 1, visited);
console.log(result.length - 1);
*/
