#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <nlohmann/json.hpp>
#include <set>
#include <iostream>

//using
using json = nlohmann::json;
using namespace std;

class EventProcessor
{
public:
    EventProcessor();

    void ProcessEvents(json& eventArray);

private:
    bool ValidateEvent(json& event);
    void RemoveDuplicates(json& eventArray);
    void StoreProcessedEvents();
    void SortEvents();


    // set<vector<json>>
    set<json>       processedEvents;
};

#endif // EVENT_PROCESSOR_H