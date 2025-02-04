#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <nlohmann/json.hpp>

//using
using json = nlohmann::json;
using namespace std;

class EventProcessor
{
public:
    EventProcessor();

    // Event Processing
    void ProcessEvents(json& eventArray);
    bool ValidateEvent(json& event);
    void SortEvents(json&   eventArray);
    void RemoveDuplicates(json& eventArray);
    void StoreProcessedEvents(const json& eventArray);

private:
    // set<vector<json>>
};

#endif // EVENT_PROCESSOR_H