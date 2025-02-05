#include "EventProcessor.h"
#include <set>

EventProcessor::EventProcessor()
              :processedEvents()
{
}

void EventProcessor::ProcessEvents(json& eventArray)
{
    for(auto& event: eventArray)
    {
        if(!ValidateEvent(event))
        {
            return;
        }
    }

    RemoveDuplicates(eventArray);
    SortEvents();
    // StoreProcessedEvents();
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
    for(auto& event: eventArray)
    {
        processedEvents.emplace(event);
    }
}

void EventProcessor::SortEvents()
{
    // Convert set to vector for sorting
    std::vector<json> eventVector(processedEvents.begin(), processedEvents.end());

    // Print before sorting
    std::cout << "Before sorting:\n";
    for (const auto& d : eventVector) {
        std::cout << d.dump(4) << std::endl;
    }

    // Sort the vector based on timestamps (ascending order)
    auto sortByTimeStamps = [] (const json& eventA, const json& eventB) -> bool
    {
        return eventA["timestamp"] < eventB["timestamp"];  // Smallest timestamp first
    };

    std::sort(eventVector.begin(), eventVector.end(), sortByTimeStamps);

    // Print after sorting
    std::cout << "\nAfter sorting:\n";
    for (const auto& d : eventVector) {
        std::cout << d.dump(4) << std::endl;
    }
}

void EventProcessor::StoreProcessedEvents()
{
    // Sort processed events

}

