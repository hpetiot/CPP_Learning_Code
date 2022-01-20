#include "Clock.h"

Clock::Clock() {
    _m = MinuteHand();
}

Clock::Clock(const std::vector<Event>& event_list)
    : _events { event_list } {
}

void Clock::tick() {
    _s.advence();
    std::vector<Event> list2;
    for (auto event : _events)
    {
        if (!event.notify_time(_m.get_minutes(), _s.get_seconds()))
        { list2.emplace_back(event); }
    }
    _events = list2;
}

void Clock::add_event(const Event& event) {
    _events.emplace_back(event);
}

std::ostream& operator<<(std::ostream& stream, const Clock& clock) {
    return stream << clock._m.get_minutes() << " min " << clock._s.get_seconds() << " sec";
}
/*
int main() {
    Clock c;
    for (int i = 0; i < 63; i++)
    { c.tick(); }
    std::cout << c << std::endl;
}*/