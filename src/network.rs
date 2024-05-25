use std::{sync::Arc, vec};

use nalgebra::DMatrix;
use rand::Rng;

pub struct Network {
    model_name: Option<String>,
    input_layer: Option<Vec<f64>>,
    output_layer: Option<Vec<f64>>,
    hidden_layers: Option<DMatrix<f64>>,
    debug: bool,
}

impl Network {
    pub fn new(name: String) -> Network {
        Network {
            model_name: Some(name),
            input_layer: None,
            hidden_layers: None,
            output_layer: None,
            debug: false,
        }
    }

    pub fn set_debug(&mut self, debug: bool) {
        self.debug = debug;
    }

    pub fn set_name(&mut self, name: String) {
        self.model_name = Some(name);
    }

    pub fn create_input_layer(&mut self, neurons:usize) {
        let vector:Vec<f64> = vec![0.0; neurons];
        if self.debug {
            println!("Input layers: {:?}", vector);
        }
        self.input_layer = Some(vector);
    }

    pub fn create_output_layer(&mut self, neurons:usize) {
        let vector:Vec<f64> = vec![0.0; neurons];
        if self.debug {
            println!("Output layers: {:?}", vector);
        }
        self.output_layer = Some(vector);
    }

    pub fn create_hidden_layer(&mut self, layers: usize, neurons_by_layer: usize) {
        let matrix:DMatrix<f64> = DMatrix::from_element(layers, neurons_by_layer, 0.0);
        if self.debug {
            println!("Hidden layers: {}", matrix);
        }

        self.hidden_layers = Some(matrix);
    }

    pub fn randomize_weights(&mut self) {
        let mut rng = rand::thread_rng();
        let mut hidden_layers = self.hidden_layers.as_mut().unwrap();
        let mut input_layer = self.input_layer.as_mut().unwrap();
        let mut output_layer = self.output_layer.as_mut().unwrap();

        for i in 0..input_layer.len() {
            input_layer[i] = rng.gen_range(-1.0..1.0);
            if self.debug {
                println!("Input layer[{}]: {}", i, input_layer[i]);
            }
        }

        for i in 0..output_layer.len() {
            output_layer[i] = rng.gen_range(-1.0..1.0);
            if self.debug {
                println!("Output layer[{}]: {}", i, output_layer[i]);
            }
        }

        for i in 0..hidden_layers.nrows() {
            for j in 0..hidden_layers.ncols() {
                hidden_layers[(i, j)] = rng.gen_range(-1.0..1.0);
                if self.debug {
                    println!("Hidden layer[{}, {}]: {}", i, j, hidden_layers[(i, j)]);
                }
            }
        }
    }

    pub fn describe(&self) {
        println!("Model name: {}", self.model_name.as_ref().unwrap_or(&"null".to_string()));
        println!("Input layers: {:?}", self.input_layer.as_ref().unwrap().len());
        println!("Output layers: {:?}", self.output_layer.as_ref().unwrap().len());
        println!("Hidden layers: {:?}", self.hidden_layers.as_ref().unwrap().shape());
    }

    pub fn get_model_name(&self) -> String {
        self.model_name.as_ref().unwrap().to_string()
    }
    
}