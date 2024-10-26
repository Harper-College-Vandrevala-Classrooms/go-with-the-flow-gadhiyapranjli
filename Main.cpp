#include "HeatFlow.h"

int main() {
    std::map<int, float> sources_and_sinks = {{0, 100.0}};
    float initial_temperature = 10;
    int number_of_sections = 5;
    float K = 0.1;

    HeatFlow h(initial_temperature, number_of_sections, K, sources_and_sinks);
    h.pretty_print();

    h.tick();
    h.pretty_print();

    h.tick();
    h.pretty_print();

    return 0;
}
