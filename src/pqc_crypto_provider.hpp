#ifndef PQC_CRYPTO_PROVIDER_HPP
#define PQC_CRYPTO_PROVIDER_HPP

#include "crypto_engine.hpp"
#include <vector>
#include <cstdint>
#include <string>

/**
 * @class OqsWrapperEngine
 * @brief An advanced C++ wrapper simulating integration with the liboqs (Open Quantum Safe) C-API.
 * Demonstrates RAII principles for secure cryptographic memory management.
 */
class OqsWrapperEngine : public ICryptoGateway {
public:
    OqsWrapperEngine();
    ~OqsWrapperEngine() override;

    std::string get_algorithm_name() const override;
    size_t get_signature_size_bytes() const override;
    std::string get_security_status() const override;
    
    // The actual heavy lifting is moved to the .cpp file
    bool verify_agent_token(const std::string& token_payload) override;

private:
    // Simulating secure memory buffers for quantum keys
    std::vector<uint8_t> public_key_buffer_;
    std::vector<uint8_t> signature_buffer_;
    
    bool is_initialized_;
    void secure_memory_wipe();
};

#endif // PQC_CRYPTO_PROVIDER_HPP
