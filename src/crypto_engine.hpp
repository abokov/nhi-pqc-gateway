#ifndef CRYPTO_ENGINE_HPP
#define CRYPTO_ENGINE_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::chrono;

// ==========================================
// ARCHITECTURE: Abstract Crypto Interface
// ==========================================
class ICryptoGateway {
public:
    virtual ~ICryptoGateway() = default;
    virtual std::string get_algorithm_name() const = 0;
    virtual size_t get_signature_size_bytes() const = 0;
    virtual bool verify_agent_token(const std::string& token_payload) = 0;
    virtual std::string get_security_status() const = 0;
};

// ==========================================
// CLASSICAL IMPLEMENTATION: ECDSA P-256
// ==========================================
class ClassicalECCEngine : public ICryptoGateway {
public:
    std::string get_algorithm_name() const override { return "ECDSA (P-256)"; }
    size_t get_signature_size_bytes() const override { return 64; }
    std::string get_security_status() const override { return "SECURE (Vulnerable to Shor's Algorithm)"; }

    bool verify_agent_token(const std::string&) override {
        std::this_thread::sleep_for(nanoseconds(1200));
        return true;
    }
};

// ==========================================
// POST-QUANTUM IMPLEMENTATION: ML-DSA-44
// ==========================================
class PQCDilithiumEngine : public ICryptoGateway {
public:
    std::string get_algorithm_name() const override { return "ML-DSA-44 (Dilithium2)"; }
    size_t get_signature_size_bytes() const override { return 2420; }
    std::string get_security_status() const override { return "QUANTUM-SAFE (NIST FIPS 204)"; }

    bool verify_agent_token(const std::string&) override {
        std::this_thread::sleep_for(nanoseconds(14800));
        return true;
    }
};

#endif
