#include "GunFactory.h"
#include "GunDefault.h"
#include "GunDouble.h"

GunDefault* GunFactory::createObject(const std::string& gunType)
{
    std::unordered_map<std::string, std::function<GunDefault* ()>> gunMap;
    gunMap["default_gun"] = []() { return new GunDefault("Default Gun"); };
    gunMap["double_gun"] = []() { return new GunDouble("Double Gun"); };

    if (gunMap.find(gunType) != gunMap.end()) {
        return gunMap[gunType]();
    }
    return gunMap["default_gun"]();
}