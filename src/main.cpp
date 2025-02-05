#include <iostream>
#include "EventGenerator.h"
#include "EventProcessor.h"


int main() {
    std::cout << "Playback Pipeline Running..." << std::endl;

    // Generate data 
    EventGenerator eventGenerator = EventGenerator(10);
    bool newData = eventGenerator.GenerateDataList();
    
    if(newData)
    {
        string filename = "Event.json";
        eventGenerator.WriteToFile(filename); 
    }

    // Process data
    EventProcessor processor = EventProcessor();
    json& data = eventGenerator.GetEventDataList();
    processor.ProcessEvents(data);

    


    return 0;
}
