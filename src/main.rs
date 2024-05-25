use std::env;

mod io;
mod network;

fn main(){
    let args: Vec<String> = env::args().collect();

    print!("Args: ");
    for arg in args.iter() {
        print!("{} \n", arg);
    }

    let mut io = io::Io::new();

    io.input();

    let mut network = network::Network::new("test".to_string());

    network.create_input_layer(3);
    network.create_output_layer(3);
    network.create_hidden_layer(3, 3);
    network.randomize_weights();
    network.describe();

    io.set_network(network);
    io.input();
}
