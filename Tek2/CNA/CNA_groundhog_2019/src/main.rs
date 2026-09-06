/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** main.rs
*/

use std::{
    env::args,
    io::{stdin, BufRead, Stdin, Error},
    process::exit,
    str::FromStr,
};

const STOP_PROG: &str = "STOP";
const USAGE_MSG: &str = "SYNOPSIS\n    ./groundhog period\n\nDESCRIPTION\n    period        the number of days defining a period";

struct HandleArgs;

#[derive(Debug)]
struct Groundhog {
    period: usize,
    stop: bool,
    switch: usize,
    weird: Vec<f64>,
    value: Vec<f64>,
    average: Vec<f64>,
    indicator: [Option<f64>; 3],
}

impl HandleArgs {
    fn get_period() -> Result<usize, i32> {
        let args: Vec<String> = args().collect();
        if args.len() == 2 {
            match &args[1][..] {
                "-h" => return Ok(0),
                nb => match usize::from_str_radix(nb, 10) {
                    Ok(period) if period > 0 => return Ok(period),
                    _ => return Err(84),
                }
            }
        }
        Err(84)
    }
}

impl Groundhog {
    fn new(period: usize) -> Self {
        Self {
            period,
            stop: false,
            switch: 0,
            weird: Vec::new(),
            value: Vec::new(),
            average: Vec::new(),
            indicator: [None; 3],
        }
    }
    fn check_end(&mut self, buff: &str) -> Option<i32> {
        if let "\n" = buff {
            return Some(1);
        }
        match buff.trim() {
            STOP_PROG => Some(0),
            "" => Some(84),
            _ => None,
        }
    }
    fn fill(&mut self, x: f64) {
        if let Some(last) = self.value.last() {
            self.average.push(x - last);
            if self.average.len() > self.period {
                self.average.remove(0);
            }
        }
        self.value.push(x);
        self.weird.push(x);
        if self.value.len() > self.period + 1 {
            self.value.remove(0);
        }
    }
    fn compute(&mut self) {
        if self.value.len() > self.period {
            let mut res = 0.0;
            for i in 1..self.value.len() {
                let avrg = self.value[i] - self.value[i - 1];
                if avrg > 0.00 {
                    res += avrg;
                }
            }
            res /= self.period as f64;
            self.indicator[0] = Some(res);
            if self.value[0] == 0.0 {
                self.indicator[1] = None;
            } else {
                self.indicator[1] = Some((self.value.last().unwrap().abs() - self.value[0]) / self.value[0] * 100.0);
            }
        }
        if self.value.len() >= self.period {
            let value = &self.value[self.value.len() - self.period..];
            let average = value.iter().sum::<f64>() / self.period as f64;
            self.indicator[2] = Some(0.0);
            for i in &value.to_vec() {
                self.indicator[2] = Some(self.indicator[2].unwrap() + (i - average).powi(2));
            }
            self.indicator[2] = Some((self.indicator[2].unwrap() / self.period as f64).sqrt());
        }
    }
    fn print(&mut self) {
        static mut SWITCH: Option<f64> = None;
        let mut display = ["nan".to_owned(), "nan".to_owned(), "nan".to_owned()];
        for i in 0..3 {
            if let Some(value) = self.indicator[i] {
                display[i] = match i {
                    1 => format!("{:.0}", value),
                    _ => format!("{:.2}", value),
                };
            }
        }
        print!("g={}\t\tr={}%\t\ts={}", display[0], display[1], display[2]);
        unsafe {
            if SWITCH != None && self.indicator[1] != None && ((self.indicator[1].unwrap() > 0.0 && SWITCH.unwrap() < 0.0) || (self.indicator[1].unwrap() < 0.0 && SWITCH.unwrap() > 0.0)) {
                print!("\t\ta switch occurs");
                self.switch += 1;
            }
            if self.indicator[1] != None {
                SWITCH = self.indicator[1];
            }
        }
        println!("");
    }
    fn print_end(&mut self) -> Result<(), i32> {
        if self.indicator[0] == None && self.indicator[1] == None && self.indicator[2] == None {
            return Err(84);
        }
        let mut weirds: Vec<f64> = Vec::new();
        for i in 0..self.weird.len() - 3 {
            if (((self.weird[i] + self.weird[i + 2]) / 2.0) - self.weird[i + 1]).abs() > 1.50 {
                weirds.push(self.weird[i + 1]);
            }
        }
        println!("Global tendency switched {} times", self.switch);
        print!("{} weirdest values are [", weirds.len());
        if weirds.len() > 1 {
            for i in 0..weirds.len() - 2 {
                print!("{:.2}, ", weirds[i]);
            }
        }
        if weirds.len() > 0 {
            println!("{:.2}]", weirds[weirds.len() - 1]);
        } else {
            println!("]");
        }
        self.stop = true;
        Ok(())
    }
    fn eval(&mut self, line: Result<String, Error>) -> Result <(), i32>{
        match line {
            Err(_) => Err(84),
            Ok(buff) => {
                match self.check_end(&buff) {
                    Some(0) => self.print_end(),
                    Some(1) => Ok(()),
                    Some(_) => Err(84),
                    None => match f64::from_str(&buff.trim()) {
                        Err(_) => Err(84),
                        Ok(x) => {
                            self.fill(x);
                            self.compute();
                            Ok(self.print())
                        },
                    },
                }
            },
        }
    }
    fn repl(mut self, input: Stdin) -> Result<(), i32> {
        for line in input.lock().lines() {
            self.eval(line)?;
            if self.stop == true {
                return Ok(());
            }
        }
        Err(84)
    }
    fn launch() -> Result<(), i32> {
        match HandleArgs::get_period() {
            Ok(0) => Ok(println!("{}", USAGE_MSG)),
            Ok(period) => Self::new(period).repl(stdin()),
            Err(code) => Err(code),
        }
    }
}

fn main() {
    exit(match Groundhog::launch() {
        Ok(()) => 0,
        Err(code) => code,
    });
}