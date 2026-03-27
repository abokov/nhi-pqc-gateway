#ifndef TOKEN_CACHE_HPP
#define TOKEN_CACHE_HPP

#include <unordered_map>
#include <string>
#include <mutex>

/**
 * @class AgentTokenCache
 * @brief In-memory LRU cache to bypass heavy ML-DSA math for high-frequency A2A loops.
 */
class AgentTokenCache {
public:
    static AgentTokenCache& getInstance() {
        static AgentTokenCache instance;
        return instance;
    }

    bool check_cache(const std::string& token_hash) {
        std::lock_guard<std::mutex> lock(mutex_);
        return cache_.find(token_hash) != cache_.end();
    }

    void add_to_cache(const std::string& token_hash) {
        std::lock_guard<std::mutex> lock(mutex_);
        cache_[token_hash] = true;
        // In a real system, this would have a TTL (Time To Live) eviction policy
    }

    size_t get_cache_size() {
        std::lock_guard<std::mutex> lock(mutex_);
        return cache_.size();
    }

private:
    AgentTokenCache() = default;
    std::unordered_map<std::string, bool> cache_;
    std::mutex mutex_;
};

#endif // TOKEN_CACHE_HPP
