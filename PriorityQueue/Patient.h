#pragma once
#include <cstdint>
#include <string>

struct Patient {
    std::string firstName;
    std::string lastName;
    uint8_t age;
    char gender;
    uint32_t priority;
};