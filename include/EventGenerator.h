
#ifndef EVENT_GENERATOR_H
#define EVENT_GENERATOR_H

#include <vector>
#include <string>
#include <tuple>
#include <nlohmann/json.hpp>


// namespace
using json = nlohmann::json;
using namespace std;

class EventGenerator
{
public:
    EventGenerator(uint32_t n);
    EventGenerator() = delete;

    bool GenerateDataList();
    json& GetEventDataList();
    void WriteToFile(const string& fileName);


private:
    json            dataEventList;
    uint32_t        parameterNumber;
};
#endif // EVENT_GENERATOR_H
