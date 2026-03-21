# 🛡️ nhi-pqc-gateway

![C++20](https://img.shields.io/badge/C++-20-blue.svg)
![Standard](https://img.shields.io/badge/Crypto-FIPS%20204%20(ML--DSA)-green.svg)
![Ecosystem](https://img.shields.io/badge/Ecosystem-Okta%20%7C%20OIDC-orange.svg)

**High-performance, quantum-resistant proxy for high-velocity Non-Human Identity (NHI) and Agentic AI workloads.**

As enterprises transition to Post-Quantum Cryptography (PQC), traditional Identity Providers face a critical bottleneck: PQC signatures (like ML-DSA) are significantly larger than RSA/ECC. For autonomous AI agents executing thousands of micro-transactions per second, standard PQC handshakes introduce paralyzing latency. 

`nhi-pqc-gateway` is a C++ offload engine that handles quantum-safe cryptographic termination at the edge, ensuring secure Agent-to-Agent (A2A) federation without degrading LLM workflow speeds.

---

## 🎯 Strategic Value (The PQC + AI Intersection)

Identity is moving from Human-to-Machine (H2M) to Machine-to-Machine (M2M) at an unprecedented scale. This gateway demonstrates the infrastructure required to secure the next decade of Okta's ecosystem:

* **Zero-Latency PQC Offload:** Terminates ML-KEM (Kyber) key exchanges and ML-DSA (Dilithium) signature verification in optimized C++, preventing the main Okta policy engine from being compute-bound.
* **Agentic Token Chaining:** Verifies quantum-signed JWTs (RFC 8693) to maintain cryptographic chain-of-custody when one AI model delegates a task to another.
* **Session Resumption for High-Frequency Loops:** Implements custom caching for AI agents communicating in tight recursive loops, minimizing the overhead of repeated PQC handshakes.

---

## 🛠️ Technical Stack

* **Core Engine:** C++20 (Optimized memory arenas for handling large PQC keys)
* **Cryptography:** `OpenSSL 3.x` + `liboqs` (Open Quantum Safe provider)
* **Concurrency:** Asynchronous non-blocking I/O (`epoll` / `kqueue`)
* **Build System:** CMake

---

## 🚀 Quick Start (Simulation Mode)

*Note: This repository currently provides a simulation harness to benchmark the latency difference between Classical ECC and Post-Quantum algorithms for agentic token verification.*

### 1. Install Dependencies (Ubuntu/Debian)
Ensure you have the Open Quantum Safe library and modern CMake.
```bash
sudo apt-get update
sudo apt-get install cmake g++ libssl-dev
# Requires liboqs to be built and installed locally
```



