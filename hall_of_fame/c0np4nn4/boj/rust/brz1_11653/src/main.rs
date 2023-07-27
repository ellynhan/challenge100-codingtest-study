use std::io::{self, BufRead};

fn get_n() -> u32 {
    let mut input = String::default();

    let stdin = io::stdin();

    let mut handle = stdin.lock();

    handle.read_line(&mut input).unwrap();

    input.trim().parse::<u32>().unwrap()
}


fn main() {
    let mut n = get_n();

    let mut p = 2;

    while n > 1 {
        if n % p == 0 {
            println!("{}", p);

            n /= p;

            p = 2;
        }
        
        else {
            p += 1;
        }
    }
}
