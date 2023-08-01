use std::io::{self, BufRead};

fn get_stdin() -> String {
    let mut input = String::default();

    let stdin = io::stdin();

    let mut handle = stdin.lock();

    handle.read_line(&mut input).unwrap();

    input
}

fn get_u32() -> u32 {
    get_stdin().trim().parse::<u32>().unwrap()
}

fn fibo(dp:&mut Vec<u32>, n: u32) -> u32 {
    if n == 0 {
        return dp[0];
    }
    else if n == 1 {
        return dp[1];
    }
    else if dp[n as usize] == 0 {
        dp[n as usize] = fibo(dp, n - 2) + fibo(dp, n - 1);
        return dp[n as usize];
    }
    return dp[n as usize];
}

fn main() {
    let mut dp: Vec<u32> = Vec::<u32>::default();
    dp.push(0);
    dp.push(1);
    for i in 0..39 {
        dp.push(0);
    }

    let t: u32 = get_u32();

    for i in 0..t {
        let n = get_u32();

        if n == 0 {
            println!("1 0");
        }
        else {
            println!("{} {}", fibo(&mut dp, n - 1), fibo(&mut dp, n));
        }
    }
}
