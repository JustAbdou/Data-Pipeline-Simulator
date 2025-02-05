#include "EventProcessor.h"
#include <set>

EventProcessor::EventProcessor()
              :processedEvents()
{
}

void EventProcessor::ProcessEvents(json& eventArray)
{
    json validEvents = json::array();

    for (auto& event : eventArray)
    {
        if (ValidateEvent(event))
        {
            validEvents.push_back(event);
        }
        else
        {
            std::cerr << "Skipping invalid event: " << event.dump(4) << std::endl;
        }
    }

    RemoveDuplicates(validEvents);
    SortEvents();
    StoreProcessedEvents();
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

void EventProcessor::RemoveDuplicates(json& eventArray)
{
    // Remove duplicates
    set<json> arr{eventArray.begin(), eventArray.end()};

    // Append them to the final array
    for(auto& event: arr)
    {
        processedEvents.push_back(event);
    }
}

void EventProcessor::SortEvents()
{
    // Sort the vector based on timestamps (ascending order)
    auto sortByTimeStamps = [] (const json& eventA, const json& eventB) -> bool
    {
        return eventA["timestamp"] < eventB["timestamp"];  // Smallest timestamp first
    };

    std::sort(processedEvents.begin(), processedEvents.end(), sortByTimeStamps);
}

void EventProcessor::StoreProcessedEvents()
{
    // Sort processed events

}

