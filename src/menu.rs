pub struct Menu {
    model_loaded: i8,
    model_name: Option<String>,
    network: Option<String>, // TODO: change to Network
}

impl Menu {
    pub fn new() -> Menu {
        Menu {
            model_loaded: 0,
            model_name: None,
            network: None,
        }
    }

    pub fn print_status(&self) {
        println!("Model loaded: {}", self.model_loaded);
        println!("Model name: {}", self.model_name.as_ref().unwrap_or(&"null".to_string()));
    }

    pub fn input(&self) -> String {
        print!("<nnc {}> {}@{}: ", VERSION, VERSION_NAME, self.model_name.as_ref().unwrap_or(&"no-model".to_string()));
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input
    }
}