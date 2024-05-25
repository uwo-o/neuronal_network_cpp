use crate::network::Network;
use crate::activation::Activation;

pub struct Trainer {
    network: Network,
    learning_rate: f64,
    epochs: usize,
    debug: bool,
    activation: Activation,
}

impl Trainer {
    pub fn new(network: Network) -> Trainer {
        Trainer {
            network: network,
            learning_rate: 0.1,
            epochs: 1000,
            debug: false,
            activation: Activation::Sigmoid,
        }
    }

    pub fn set_learning_rate(&mut self, learning_rate: f64) {
        self.learning_rate = learning_rate;
    }

    pub fn set_epochs(&mut self, epochs: usize) {
        self.epochs = epochs;
    }

    pub fn set_debug(&mut self, debug: bool) {
        self.debug = debug;
    }

}