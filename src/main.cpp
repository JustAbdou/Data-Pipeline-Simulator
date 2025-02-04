#include <iostream>
#include "EventGenerator.h"

int main() {
    // Generate data 
    EventGenerator eventGenerator = EventGenerator(10);
    bool newData = eventGenerator.GenerateDataList();
    
    if(newData)
    {
        string filename = "Event.json";
        eventGenerator.WriteToFile(filename);
    }

    std::cout << "Playback Pipeline Running..." << std::endl;
    return 0;
}
