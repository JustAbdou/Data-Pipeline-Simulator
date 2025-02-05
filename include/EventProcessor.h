#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <nlohmann/json.hpp>
#include <set>
#include <iostream>
#include <vector>
#include <mutex>

//using
using json = nlohmann::json;
using namespace std;

class EventProcessor
{
public:

    EventProcessor();

    void        ProcessEvents(json& eventArray);
    json&       GetProcessedData();

private:

    bool        ValidateEvent(json& event);
    void        RemoveDuplicates(json& eventArray);
    void        StoreProcessedEvents();
    void        SortEvents();


    // set<vector<json>>
    vector<json>       processedEvents;
};

#endif // EVENT_PROCESSOR_H