#include "EventProcessor.h"
#include <set>

EventProcessor::EventProcessor()
{
}

void EventProcessor::ProcessEvents(json& eventArray)
{
    RemoveDuplicates(eventArray);
    SortEvents(eventArray);
    StoreProcessedEvents(eventArray);
}

bool EventProcessor::ValidateEvent(json& event) 
{
    // Required fields
    static const std::set<std::string> fields{"username", "track", "eventType", "timestamp"};

    for (const auto& field : fields) 
    {
        // Check if the field exists
        if (!event.contains(field) || event[field].is_null()) 
        {
            return false;
        }
    }
    return true;
}

void EventProcessor::RemoveDuplicates(json& event)
{

}
