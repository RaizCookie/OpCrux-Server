#ifndef __REPLICA__COMPONENTS__ITEM_COMPONENT_HPP__
#define __REPLICA__COMPONENTS__ITEM_COMPONENT_HPP__

#include "Entity/Components/Interface/IEntityComponent.hpp"
#include "Entity/GameObject.hpp"

#include "GameCache/ComponentsRegistry.hpp"
#include "GameCache/MovementAIComponent.hpp"
#include "Utils/ServerInfo.hpp"

using namespace DataTypes;

class ItemComponent : public IEntityComponent {
private:

	

public:

	ItemComponent() : IEntityComponent() {}

};

#endif