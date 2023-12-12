#[allow(dead_code)]
#[allow(unused_imports)]
// Based on: https://github.com/EbTech/rust-algorithms/blob/master/src/scanner.rs
use std::io;
use std::str;

/// Reads white-space separated tokens one at a time.
pub struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}

impl<R: io::BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: vec![],
        }
    }

    /// Use "turbofish" syntax token::<T>() to select data type of next token.
    pub fn token<T: str::FromStr>(&mut self) -> Option<T> {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok();
            }

            let mut input = String::new();
            if let Err(_) = self.reader.read_line(&mut input) {
                return None;
            }

            if input.len() == 0 {
                return None;
            }

            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

const NUMBERS: [&'static str; 9] = [
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
];

fn get_number(input: &String, idx: usize) -> Option<u32> {
    let b = input.as_bytes();

    {
        let c = b[idx] as char;
        if c.is_ascii_digit() {
            return Some(c.to_digit(10).unwrap());
        }
    }

    for (i, num) in NUMBERS.iter().enumerate() {
        let l = num.len();
        if idx + l <= input.len() && b[idx..idx + l] == *num.as_bytes() {
            return Some(i as u32 + 1);
        }
    }

    None
}

fn proc(input: &String) -> u32 {
    let mut a: Option<u32> = None;
    let mut b: Option<u32> = None;

    let mut i = 0;
    while i < input.len() {
        if let Some(n) = get_number(input, i) {
            if a.is_none() {
                a = Some(n);
            }
            b = Some(n);
        }

        i += 1;
    }

    a.unwrap() * 10 + b.unwrap()
}

fn main() {
    let mut sc = Scanner::new(io::stdin().lock());

    let mut s: u32 = 0;

    while let Some(input) = sc.token::<String>() {
        s += proc(&input);
    }

    println!("{}", s);
}
