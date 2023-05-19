const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  input = input.map((item) => item.split(" ").map(Number)).reverse();
  main();

  process.exit();
});

function main() {
  const vertexSize = 1_000_000;

  const [n, m] = input.pop();
  const parent = Array.from({ length: vertexSize + 1 }, (_, i) => i);
  let answer = "";

  for (let i = 0; i < m; i++) {
    const [op, a, b] = input.pop();

    if (op === 1) {
      const A = find(a);
      const B = find(b);

      if (A === B) answer += "YES\n";
      if (A !== B) answer += "NO\n";
    }
    if (op === 0) merge(a, b);
  }

  console.log(answer);

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
}
