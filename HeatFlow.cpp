#include "HeatFlow.h"

HeatFlow::HeatFlow(float initial_temperature, int num_sections, float K, const std::map<int, float>& sources_and_sinks)
    : num_sections(num_sections), K(K), temperatures(num_sections, initial_temperature), sources_and_sinks(sources_and_sinks) {
    
    for (const auto& source : sources_and_sinks) {
        if (source.first >= 0 && source.first < num_sections) {
            temperatures[source.first] = source.second;
        }
    }
}

void HeatFlow::tick() {
    std::vector<float> new_temperatures = temperatures;

    for (int i = 0; i < num_sections; ++i) {
        if (sources_and_sinks.count(i) > 0) {
            new_temperatures[i] = sources_and_sinks.at(i);  
        } else {
            float left = (i > 0) ? temperatures[i - 1] : temperatures[i];
            float right = (i < num_sections - 1) ? temperatures[i + 1] : temperatures[i];
            new_temperatures[i] = temperatures[i] + K * (right - 2 * temperatures[i] + left);
        }
    }
    temperatures = new_temperatures;
}

void HeatFlow::pretty_print() const {
    std::cout << "+";
    for (int i = 0; i < num_sections; ++i) std::cout << "-------+";
    std::cout << "\n|";
    for (float temp : temperatures) std::cout << std::setw(6) << temp << " |";
    std::cout << "\n+";
    for (int i = 0; i < num_sections; ++i) std::cout << "-------+";
    std::cout << "\n";
}
