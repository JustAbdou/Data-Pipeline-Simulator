#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <nlohmann/json.hpp>
#include <set>
#include <future>
#include <mutex>
#include <iostream>
#include <algorithm>

//using
using json = nlohmann::json;
using namespace std;

class EventProcessor
{
public:

    EventProcessor();

    void                ProcessEvents(json& eventArray);
    vector<json>        GetProcessedData() { return processedEvents; }

private:

    bool                ValidateEvent(json& event);
    void                RemoveDuplicates(json& eventArray);
    void                StoreProcessedEvents();
    void                SortEvents();

    std::mutex               eventMutex;
    // set<vector<json>>
    vector<json>       processedEvents;
};

#endif // EVENT_PROCESSOR_H