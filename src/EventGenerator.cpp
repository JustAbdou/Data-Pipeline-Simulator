#include "EventGenerator.h"

// Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>


EventGenerator::EventGenerator(uint32_t n)
                : parameterNumber(n)
                , dataEventList(json::array())
{
}

bool EventGenerator::GenerateDataList()
{
    if(dataEventList.empty())
    {
        return false;
    }

    static const vector<string> eventTypes{"pause", "resume", "skip"};

    for(uint32_t i = 0; i < parameterNumber; i++)
    {
        const string username   = "username" + to_string(rand() % parameterNumber);
        const string track      = string("track") + static_cast<char>(std::toupper(char('a' + rand() % 26)));
        const int eventID       = rand() % eventTypes.size();

        json data = 
        {
            {"username", username},
            {"track", track},
            {"eventType", eventTypes[eventID]},
            {"timestamp", rand() % 1334}
        };
        dataEventList.push_back(data);
    }

    return true;
}

void EventGenerator::WriteToFile(const string& fileName)
{
    // This should be changed later
    string filePath = "C:/Users/Abdo/Desktop/Data-Pipeline-Simulator/" + fileName;
    ofstream file(filePath);
    if (file.is_open()) 
    {
        cout << "File successfully written: " << filePath << endl;
        file << dataEventList.dump(4);
        file.close();
    } 
    else 
    {
        cerr << "Error: Unable to open file at " << filePath << endl;
    }
}


json& EventGenerator::GetEventDataList()
{
    return dataEventList;
}