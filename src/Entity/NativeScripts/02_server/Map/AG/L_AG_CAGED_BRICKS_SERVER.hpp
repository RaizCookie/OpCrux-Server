#ifndef __ENTITY__NATIVESCRIPTS__02_SERVER__MAP__AG__L_AG_CAGED_BRICKS_SERVER_HPP__
#define __ENTITY__NATIVESCRIPTS__02_SERVER__MAP__AG__L_AG_CAGED_BRICKS_SERVER_HPP__

#include <string>
#include "Entity/GameObject.hpp"
#include "Entity/NativeScript.hpp"
#include "Entity/Components/CharacterComponent.hpp";
#include "Entity/Components/InventoryComponent.hpp";
#include <memory>

class NATIVESCRIPT__02_SERVER__MAP__AG__L_AG_CAGED_BRICKS_SERVER : public NativeScript {

	const std::u16string spiderGroup = u"cagedSpider";
	const std::u16string preconID = u"188;189";
	const std::int32_t flagID = 74;
	const std::int32_t invenItem = 14553;

public:

	void onUse(Entity::GameObject* self, GM::RequestUse msg) {
		auto spiderObj = self->GetZoneInstance()->objectsManager->GetObjectsInGroup(spiderGroup, self->GetObjectID(), true);
	
		Logger::log("SCRPT", "CAGED_BRICKS ");
		for (auto obj : spiderObj) {
			if (obj != nullptr) {
				Logger::log("SCRPT", "NO NULLPOINTER!");
				// tell the spider to show up
				{
					GM::FireEventClientSide nmsg;
					Logger::log("SCRPT", "Declared FireEventClientSide");
					nmsg.args = u"toggle";
					Logger::log("SCRPT", "Defined args");
					nmsg.senderID = msg.user->GetObjectID();
					std::string objid = "OBJID:";
					std::ostringstream o;
					o << std::uint64_t(msg.user->GetObjectID()) << "  ObjOfObjID:" << std::uint64_t(obj->GetObjectID()); //Debug stuff
					objid += o.str();
					Logger::log("SCRPT", "Got ObjectID " + objid);
					GameMessages::Send(msg.user, obj->GetObjectID(), nmsg);
					Logger::log("SCRPT", "Sent GameMessage");
				}
				Logger::log("SCRPT", "SPIDER SHOWUP");
				// set the mission player flag
				msg.user->GetComponent<CharacterComponent>()->SetFlag(flagID, true);
				Logger::log("SCRPT", "FLAG SET");
				// Player has completed the mission, remove necessary items
				msg.user->GetComponent<InventoryComponent>()->RemoveItem2(invenItem, 1);
				Logger::log("SCRPT", "REMOVED ITEM");
			}
		}

	}

};
#endif 