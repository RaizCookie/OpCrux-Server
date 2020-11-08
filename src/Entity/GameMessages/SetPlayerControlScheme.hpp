#ifndef __ENTITY__GM__SetPlayerControlScheme_HPP__
#define __ENTITY__GM__SetPlayerControlScheme_HPP__
#include "Entity/GameMessages.hpp"

namespace GM {
	struct SetPlayerControlScheme : GMBase {

		inline constexpr static Enums::EGameMessageID GetID() {
			return Enums::EGameMessageID::SET_PLAYER_CONTROL_SCHEME;
		}

		bool bDelayCamSwtichIfInCinematic = false;
		bool bSwitchCam = true;
		std::int32_t iScheme = 0;

		SetPlayerControlScheme() : GMBase() {}

		void Serialize(RakNet::BitStream* bs) {
			GM_VAR_SERIALIZE(bs, bDelayCamSwtichIfInCinematic);
			GM_VAR_SERIALIZE(bs, bSwitchCam);
			GM_VAR_SERIALIZE(bs, iScheme);
		}
	};
}

#endif