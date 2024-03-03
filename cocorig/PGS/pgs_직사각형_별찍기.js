process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);
        
    // a = 5 , b = 3
    
    // for(let i = 0; i < b; i++){
    //      let ans = '';
    //      for(let j = 0; j < a; j++){
    //           ans += '*'
    //    }
    //    console.log(ans)
    // }
    let star = `${'*'.repeat(a)}\n`
    console.log(star.repeat(b))
    
});