use std::io::{self, BufRead};

fn get_input() -> u32 {
    let mut input = String::new();

    let stdin = io::stdin();

    let mut handle = stdin.lock();

    handle.read_line(&mut input).unwrap();

    input.trim().parse::<u32>().unwrap()
}

fn get_minimum_count(weight: u32) -> u32 {
    let mut count: u32 = 2000;

    for cnt_5 in 0..=(weight / 5) {
        let remain = weight - cnt_5 * 5;

        if remain % 3 == 0 {
            let cnt_3 = remain / 3;

            // println!("[!] cnt_3: {:?}, cnt_5: {:?}", cnt_3, cnt_5);

            if cnt_5 + cnt_3 < count {
                count = cnt_5 + cnt_3;
            }
        }
    }

    return count;
}

fn check(weight: u32) -> bool {
    for i in 0..=(weight / 5) {
        if (weight - i * 5) % 3 == 0 {
            return true;
        }
    }

    false
}

fn main() {
    let weight = get_input();

    if check(weight) == false {
        println!("-1");
    } else {
        println!("{}", get_minimum_count(weight));
    }
}

