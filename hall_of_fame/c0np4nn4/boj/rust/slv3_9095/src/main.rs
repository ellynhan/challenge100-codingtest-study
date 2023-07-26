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

fn main() {
    let mut comb = vec![0, 1, 2, 4];

    for i in 4..=11 {
        comb.push(comb[i-3] + comb[i-2] + comb[i-1]);
    }

    let t = get_u32();

    for _ in 0..t {
        let n = get_u32();
        println!("{}", comb[n as usize]);
    }
}
