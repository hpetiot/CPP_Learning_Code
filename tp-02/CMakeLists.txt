add_executable(tp2-reminders
    Clock/Clock.cpp
    Clock/Clock.h
    Clock/MinuteHand.cpp
    Clock/MinuteHand.h
    Clock/SecondHand.cpp
    Clock/SecondHand.h
    Reminders.cpp
    Event.h
    Parsing.cpp
    Parsing.h
    
)

add_executable(tp2-Histogram
    Histogram/Histogram.h
    Histogram/Histogram.cpp
    Histogram/main.cpp)

add_executable(tp2-MinuteHand
    Clock/MinuteHand.h
    Clock/MinuteHand.cpp)

add_executable(tp2-SecondHand
    Clock/MinuteHand.h
    Clock/MinuteHand.cpp
    Clock/SecondHand.h
    Clock/SecondHand.cpp)

add_executable(tp2-Clock
    Clock/MinuteHand.h
    Clock/MinuteHand.cpp
    Clock/SecondHand.h
    Clock/SecondHand.cpp
    Clock/Clock.h
    Clock/Clock.cpp)