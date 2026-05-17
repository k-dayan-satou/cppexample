#include <cstdint>
#include <iostream>
#include <map>

static const uint64_t PORT_1 = 1;
static const uint64_t PORT_2 = 2;
static const uint64_t PORT_3 = 3;

struct PortTimer {
    uint64_t id;
    uint64_t retryCount;
    uint64_t retryOut;
};

uint64_t rTimer(uint64_t time) {
    static uint64_t tId = 0;
    return tId++;
}

std::map<uint64_t, PortTimer> portTimer = {
    {1, {0, 0, 0}},
    {2, {0, 0, 0}},
    {3, {0, 0, 0}},
};

void regTimer() {
    struct Timer {
        uint64_t portId;
        PortTimer& timer;
    } timers[] = {
        {PORT_1, portTimer[PORT_1]},
        {PORT_2, portTimer[PORT_2]},
        {PORT_3, portTimer[PORT_3]},
    };

    for (auto& t : timers) {
        t.timer.id = rTimer(1000);
    }

    for (const auto& t : portTimer) {
        std::cout << "Port: " << t.first << ", Timer ID: " << t.second.id
                  << std::endl;
    }
}

int main() {
    regTimer();

    return 0;
}
