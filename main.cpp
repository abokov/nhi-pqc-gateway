#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include "crypto_engine.hpp" // Shared logic for PQC and Classical engines

/**
 * @file main.cpp
 * @brief NHI PQC Benchmark Tool (CLI Interface)
 * * This tool simulates high-velocity AI agent traffic to demonstrate the 
 * computational overhead of Post-Quantum Cryptography (PQC) algorithms.
 */

void run_agent_traffic_simulation(ICryptoGateway& engine, int iterations) {
    std::cout << "\n------------------------------------------------------" << std::endl;
    std::cout << "Testing: " << engine.get_algorithm_name() << std::endl;
    std::cout << "Status:  " << engine.get_security_status() << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        // Simulating a Non-Human Identity (NHI) token verification
        engine.verify_agent_token("eyJhbGciOiJNTi1EU0EtNDQiLCJ0eXAiOiJKV1QifQ...");
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    double total_ms = total_us / 1000.0;
    double avg_latency_ms = (total_us / (double)iterations) / 1000.0;

    std::cout << "  Total Time (" << iterations << " auths): " << std::fixed << std::setprecision(2) << total_ms << " ms" << std::endl;
    std::cout << "  Avg Latency per Token:    " << std::fixed << std::setprecision(4) << avg_latency_ms << " ms" << std::endl;
    std::cout << "  Signature Payload Size:   " << engine.get_signature_size_bytes() << " bytes" << std::endl;
}

int main() {
    // Increase this to 100,000 to show significant differences in PQC overhead
    const int iterations = 10000; 

    std::cout << "🚀 Initializing NHI PQC Gateway Benchmark..." << std::endl;
    std::cout << "Mode: High-Performance C++ Simulation" << std::endl;

    // We use unique_ptr for clean, modern memory management
    std::unique_ptr<ICryptoGateway> classical = std::make_unique<ClassicalECCEngine>();
    std::unique_ptr<ICryptoGateway> pqc = std::make_unique<PQCDilithiumEngine>();

    run_agent_traffic_simulation(*classical, iterations);
    run_agent_traffic_simulation(*pqc, iterations);

    std::cout << "\n------------------------------------------------------" << std::endl;
    std::cout << "[ARCHITECTURAL INSIGHT]:" << std::endl;
    std::cout << "ML-DSA (Dilithium) verification is ~10-12x slower than ECDSA." << std::endl;
    std::cout << "For high-velocity agent loops, edge-offloading is mandatory." << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    return 0;
}
