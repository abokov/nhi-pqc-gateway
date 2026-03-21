# ==============================================================================
# Stage 1: Build Environment (Heavy)
# ==============================================================================
FROM ubuntu:22.04 AS builder

# Prevent interactive timezone prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy source code
COPY CMakeLists.txt .
COPY src/ ./src/

# Build the C++ benchmark
RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# ==============================================================================
# Stage 2: Production Runtime (Lightweight)
# ==============================================================================
FROM ubuntu:22.04

WORKDIR /app

# Only install runtime libraries (OpenSSL)
RUN apt-get update && apt-get install -y libssl3 && rm -rf /var/lib/apt/lists/*

# Copy the compiled binary from the builder stage
COPY --from=builder /app/build/nhi-pqc-benchmark .

# Run the simulation as the default entrypoint
ENTRYPOINT ["./nhi-pqc-benchmark"]

