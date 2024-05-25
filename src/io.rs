use std::io::{self, Write};

use crate::network::Network;
pub struct Io {
    network: Option<Network>,
}

impl Io {
    pub fn new() -> Io {
        Io {
            network: None,
        }
    }

    pub fn set_network(&mut self, network: Network) {
        self.network = Some(network);
    }

    pub fn input(&self) -> String {
        let version: &str = env!("CARGO_PKG_VERSION");
        let mut model_name: String = "None".to_string();

        if ! self.network.is_none() {
            model_name = self.network.as_ref().unwrap().get_model_name();
        }

        print!("<nnr {}> {}: ", version, model_name);
        std::io::stdout().flush().unwrap();

        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        return input;
    }
}