use std::{process::{Command, exit}, io::{self, BufRead}, path::Path, env};

fn get_stdin() -> String {
    let mut input = String::new();

    let stdin = io::stdin();

    let mut handle = stdin.lock();

    handle.read_line(&mut input).unwrap();

    input.trim().parse::<String>().unwrap()
}

fn hex_to_string(v: Vec<u8>) -> String {
    v.iter().map(|n| n.clone() as char).collect()
}

fn get_prob_name(prob_num: String) -> String {
    let arg = format!("*_{}.rs", prob_num);

    let prob_name = Command::new("find")
                .args(["./", "-name", arg.as_str()])
                .output()
                .unwrap()
                .stdout;

    let prob_name: Vec<String> = hex_to_string(prob_name).split_whitespace().map(|s| s.to_string()).collect();

    if prob_name.is_empty() {
        println!("[-] Couldn't find the file, prob_num: {:?}", prob_num);
        exit(1);
    }

    if prob_name.len() != 1 {
        println!("[-] More than one source file has been found, prob_num: {:?}", prob_num);
        exit(1);
    }

    let prob_name:String = prob_name.first().unwrap().to_owned();

    let prob_name = &prob_name[2..prob_name.len()-3];

    prob_name.to_owned()
}

fn main() {
    let path = Path::new("src/probs/");

    env::set_current_dir(path).unwrap();

    let prob_num = get_stdin();

    let prob_name = get_prob_name(prob_num);

    let res = Command::new("rustc").arg(format!("./{}.rs", prob_name)).output().unwrap();

    if !res.stderr.is_empty() {
        println!("[-] Compilation Error, err: {:?}", format!("{:?}", hex_to_string(res.stderr)));
        return;
    }

    println!("[+] Compilation Done. prob: {:?}", prob_name);

}
