use std::env;

mod menu;

fn main(){
    let args: Vec<String> = env::args().collect();
    let menu = menu::Menu::new();
    print!("args: ");
    for arg in args.iter() {
        print!("{} \n", arg);
    }
    menu.print_status();
    menu.input();
}
