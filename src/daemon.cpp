#include <iostream>
#include <iomanip>
#include <memory>
#include "crypto_engine.hpp" // 👈 This imports your "old main" code

void run_agent_traffic_simulation(ICryptoGateway& engine, int iterations) {
    std::cout << "\n[" << engine.get_algorithm_name() << "]:\n";
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        engine.verify_agent_token("simulation_payload");
    }

    auto end = high_resolution_clock::now();
    auto total_ms = duration_cast<microseconds>(end - start).count() / 1000.0;

    std::cout << "  Total Time: " << total_ms << " ms\n";
    std::cout << "  Status: " << engine.get_security_status() << "\n";
}

int main() {
    int iterations = 10000;
    std::cout << "🚀 NHI PQC Benchmark CLI Starting...\n";

    ClassicalECCEngine classical;
    PQCDilithiumEngine pqc;

    run_agent_traffic_simulation(classical, iterations);
    run_agent_traffic_simulation(pqc, iterations);

    return 0;
}
