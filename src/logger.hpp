#ifndef NHI_LOGGER_HPP
#define NHI_LOGGER_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

/**
 * @class JsonLogger
 * @brief Thread-safe structured logging for Splunk/Datadog ingestion.
 */
class JsonLogger {
public:
    enum Level { INFO, WARN, ERROR, AUDIT };

    static JsonLogger& getInstance() {
        static JsonLogger instance;
        return instance;
    }

    void log(Level level, const std::string& event, const std::string& details) {
        std::lock_guard<std::mutex> lock(mutex_);
        
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        
        // Strip the newline from ctime
        std::string time_str = std::ctime(&time_t_now);
        time_str.pop_back();

        std::string level_str;
        switch(level) {
            case INFO: level_str = "INFO"; break;
            case WARN: level_str = "WARN"; break;
            case ERROR: level_str = "ERROR"; break;
            case AUDIT: level_str = "AUDIT_TRAIL"; break;
        }

        // Output as standard JSON for log aggregators
        std::cout << "{"
                  << "\"timestamp\":\"" << time_str << "\", "
                  << "\"level\":\"" << level_str << "\", "
                  << "\"event\":\"" << event << "\", "
                  << "\"details\":\"" << details << "\""
                  << "}\n";
    }

private:
    JsonLogger() = default;
    std::mutex mutex_;
};

#define LOG_INFO(event, details) JsonLogger::getInstance().log(JsonLogger::INFO, event, details)
#define LOG_AUDIT(event, details) JsonLogger::getInstance().log(JsonLogger::AUDIT, event, details)

#endif // NHI_LOGGER_HPP
