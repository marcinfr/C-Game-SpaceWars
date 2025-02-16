#include "BulletFactory.h"
#include "BulletDefault.h"

SpaceObject* BulletFactory::createObject(const std::string& bulletType)
{
    std::unordered_map<std::string, std::function<SpaceObject* ()>> bulletsMap;
    bulletsMap["simple_bullet"] = []() { return new BulletDefault("Simple Bullet"); };

    if (bulletsMap.find(bulletType) != bulletsMap.end()) {
        return bulletsMap[bulletType]();
    }
    return bulletsMap["simple_bullet"]();
}