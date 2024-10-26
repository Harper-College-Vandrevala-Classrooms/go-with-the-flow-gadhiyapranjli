#ifndef HEATFLOW_H
#define HEATFLOW_H

#include <vector>
#include <map>
#include <iostream>
#include <iomanip>

class HeatFlow {
public:
    HeatFlow(float initial_temperature, int num_sections, float K, const std::map<int, float>& sources_and_sinks);
    void tick();
    void pretty_print() const;

private:
    int num_sections;
    float K;
    std::vector<float> temperatures;
    std::map<int, float> sources_and_sinks;
};

#endif
