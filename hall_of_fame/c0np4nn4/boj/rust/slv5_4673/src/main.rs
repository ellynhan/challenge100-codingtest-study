fn get_self_num(n: usize) -> usize {
    let mut res: usize = n;

    let mut tmp = n.clone();

    while tmp > 0 {
        res += tmp % 10;

        tmp /= 10;
    }

    return res;
}

fn main() {
    let mut num_table: [usize; 10001] = [0; 10001];

    for i in 0..10001 {
        num_table[i] = i as usize;
    }

    for i in 1..10001 {
        let mut tmp = i;

        if num_table[tmp] != 0 {
            while get_self_num(tmp) < 10001 {
                tmp = get_self_num(tmp);

                num_table[tmp] = 0;
            }
        }
    }

    for i in 1..10000 {
        if num_table[i] != 0 {
            println!("{}", num_table[i]);
        }
    }
}
