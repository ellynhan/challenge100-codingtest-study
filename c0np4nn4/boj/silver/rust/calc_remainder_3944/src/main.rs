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

fn get_tc_params() -> (u32, String) {
    let input: Vec<String> = get_stdin()
        .trim()
        .split(' ')
        .into_iter()
        .map(|s| s.to_string())
        .collect();

    // println!("a: {:?}", a);

    (
        input[0].to_string().parse::<u32>().unwrap(),
        input[1].to_string(),
    )
}

fn main() {
    let tc_cnt = get_u32();

    for _ in 0..tc_cnt {
        let (base, num_string) = get_tc_params();
        // println!("[1] base: {:?}, num: {:?}", base, num_string);

        let mut sum: u32 = 0;

        for n in num_string.into_bytes() {
            sum += n as u32 - '0' as u32;
        }

        // println!("sum: {:?}", sum);

        println!("{}", sum % (base - 1));
    }
}
