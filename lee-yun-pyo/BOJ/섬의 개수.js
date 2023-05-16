const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((v) => v.trim());

let heightIndex = 0;
while (true) {
  let height = +input[heightIndex].split(" ")[1];
  let width = +input[heightIndex].split(" ")[0];
  if (height === 0 && width === 0) return;
  const graph = input
    .slice(heightIndex + 1, heightIndex + 1 + height)
    .map((i) => i.split(" ").map((v) => +v));

  function dfs(x, y) {
    if (x >= height || x <= -1 || y >= width || y <= -1) return false;
    if (graph[x][y] === 1) {
      graph[x][y] = 999;
      dfs(x - 1, y);
      dfs(x, y - 1);
      dfs(x + 1, y);
      dfs(x, y + 1);
      dfs(x - 1, y - 1);
      dfs(x - 1, y + 1);
      dfs(x + 1, y + 1);
      dfs(x + 1, y - 1);
      return true;
    }
    return false;
  }

  let result = 0;
  for (let i = 0; i < height; i++) {
    for (let j = 0; j < width; j++) {
      if (dfs(i, j) === true) result += 1;
    }
  }

  console.log(result);

  heightIndex = heightIndex + 1 + height;
}
