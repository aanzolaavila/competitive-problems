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

fn main() {
    let mut sc = Scanner::new(io::stdin().lock());

    let mut s: i32 = 0;

    while let Some(input) = sc.token::<String>() {
        let mut a: Option<char> = None;
        let mut b: Option<char> = None;

        for c in input.chars() {
            if c.is_ascii_digit() {
                if a.is_none() {
                    a = Some(c);
                }

                b = Some(c);
            }
        }

        let v = vec![a.unwrap(), b.unwrap()];

        let ss: String = v.into_iter().collect();

        let val = ss.parse::<i32>().ok().expect("Failed to parse number");

        s += val;
    }

    println!("{}", s);
}
