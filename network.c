#include "network.h"

void neurone_connector(Neurone * input_neurones, Neurone * output_neurones, Neurone * hidden_neurones, int input_size, int output_size, int hidden_layers, int hidden_layers_size){

}

Network * create_network(int input_size, int output_size, int hidden_layers, int hidden_layers_size){

    Neurone * input_neurones = (Neurone *) malloc(sizeof(Neurone)*input_size);
    Neurone * output_neurones = (Neurone *) malloc(sizeof(Neurone)*output_size);
    Neurone * hidden_neurones = (Neurone *) malloc(sizeof(Neurone)*hidden_layers*hidden_layers_size);

    Network * network = (Network *) malloc(sizeof(Network));
}

Network * load_model(FILE * model){

    int input_size, output_size, hidden_layers, hidden_layers_size;

    fscanf(model, "%d", &input_size);
    fscanf(model, "%d", &output_size);
    fscanf(model, "%d", &hidden_layers);
    fscanf(model, "%d", &hidden_layers_size);

    printf("%d %d %d %d\n", input_size, output_size, hidden_layers, hidden_layers_size);

    Network * network = create_network(input_size, output_size, hidden_layers, hidden_layers_size);
}