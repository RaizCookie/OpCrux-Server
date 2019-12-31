#include "MissionManager.hpp"
#include "GameCache/Missions.hpp"
#include "GameCache/MissionTasks.hpp"
#include "Entity/GameObject.hpp"
#include "Entity/Components/CharacterComponent.hpp"
#include "Database/Database.hpp"
#include "Server/WorldServer.hpp"
#include "Entity/Components/CharacterComponent.hpp"
#include "Entity/GameMessages.hpp"

std::map<std::int32_t, std::map<std::int32_t, std::int32_t>> MissionManager::GetMissionTasksByTaskTypeAndTarget(Enums::EMissionTask taskType, std::int32_t target) {
    std::map<std::int32_t, std::map<std::int32_t, std::int32_t>> missionsFound;

	FDB::RowTopHeader rth = Cache.getRows("MissionTasks");
	for (int i = 0; i < rth.getRowCount(); ++i) {
		if (!rth.isValid(i)) continue;
		FDB::RowInfo rowInfo = rth[i];
        std::int32_t c_mission = CacheMissionTasks::GetID(rowInfo);
        std::map<std::int32_t, std::int32_t> tasks;
        std::int32_t taskIndex = 0;
		while (rowInfo.isValid()) {

			// Check for target first, then for taskType -> better performance
			std::int32_t c_target = CacheMissionTasks::GetTarget(rowInfo);
			if (c_target == target || c_target <= 0) {
				std::int32_t c_taskType = CacheMissionTasks::GetTaskType(rowInfo);
				if (c_taskType == static_cast<std::int32_t>(taskType)) {
                    std::int32_t c_uid = CacheMissionTasks::GetUID(rowInfo);
                    tasks.insert({ taskIndex, c_uid });
				}
			}

            if (tasks.size() != 0) {
                missionsFound.insert({ c_mission, tasks });
            }

			if (rowInfo.isLinkedRowInfoValid()) {
				rowInfo = rowInfo.getLinkedRowInfo();
			}
			else {
				break;
			}
            ++taskIndex;
		}
	}

	return missionsFound;
}

void MissionManager::UpdateMissionTask(Entity::GameObject * sender, Entity::GameObject* player, std::int32_t missionID, std::int32_t taskMask, std::float_t update) {
    GM::NotifyMissionTask msgNotifyMissionTask;
    msgNotifyMissionTask.missionID = missionID;
    msgNotifyMissionTask.taskMask = taskMask;
    msgNotifyMissionTask.updates = { update };
    GameMessages::Send(player, player->GetObjectID(), msgNotifyMissionTask);
}

void MissionManager::LaunchTaskEvent(Enums::EMissionTask taskType, Entity::GameObject * caster, DataTypes::LWOOBJID player, std::int32_t updateVal) {
    WorldServer* Instance = caster->GetZoneInstance();
    std::int64_t dbPlayerID = player.getPureID();

    Entity::GameObject* playerObject = Instance->objectsManager->GetObjectByID(player);
    if (playerObject == nullptr) return;
    if (playerObject->GetComponent<CharacterComponent>() == nullptr) return;


    std::list<Database::MissionModel> updateMissions = {};


    auto possibleMissions = GetMissionTasksByTaskTypeAndTarget(taskType, caster->GetLOT());

    if (possibleMissions.size() != 0) {
        std::list<std::int32_t> possibleMissionsOM = {};
        for (auto it = possibleMissions.begin(); it != possibleMissions.end(); ++it) {
            possibleMissionsOM.push_back(it->first);
        }

        auto currentMissions = Database::GetAllMissionsByIDsAndStates(dbPlayerID, possibleMissionsOM, { 2, 10 });
    
        switch (taskType)
        {
        case Enums::EMissionTask::KILL:
            break;
        case Enums::EMissionTask::SCRIPT:
            break;
        case Enums::EMissionTask::WIN_ACTIVITY:
            break;
        case Enums::EMissionTask::COLLECTIBLE: {
            for (auto it = currentMissions.begin(); it != currentMissions.end(); ++it) {
                auto missionModel = *it;


                auto missionTasksProgress = StringUtils::splitString(it->progress, '|');
                auto updateTasks = possibleMissions.at(it->missionID);

                std::int32_t subTaskValue = (caster->GetZoneInstance()->luZone->zoneID << 8) + (updateVal & 0xFF);

                for (int i = 0; i < missionTasksProgress.size(); ++i) {

                    auto subTaskProgStr = StringUtils::splitString(missionTasksProgress.at(i), ':');
                    auto subTaskProg = StringUtils::StringVectorToIntList(subTaskProgStr);

                    if (std::find(subTaskProg.begin(), subTaskProg.end(), subTaskValue) == subTaskProg.end()) {
                        subTaskProg.push_back(subTaskValue);

                        UpdateMissionTask(caster, playerObject, missionModel.missionID, 1 << (i + 1), subTaskValue);
                    }

                    missionTasksProgress.at(i) = StringUtils::IntListToString(subTaskProg, ':');
                }

                missionModel.progress = StringUtils::StringVectorToString(missionTasksProgress, '|');
                updateMissions.push_back(missionModel);
            }
            break;
        }
        case Enums::EMissionTask::TALK_TO_NPC: {
            auto currentMissions = Database::GetAllMissionsByIDsAndStates(dbPlayerID, possibleMissionsOM, { 2, 10 });
            for (auto it = currentMissions.begin(); it != currentMissions.end(); ++it) {
                auto missionModel = *it;


                auto missionTasksProgress = StringUtils::splitString(it->progress, '|');
                auto updateTasks = possibleMissions.at(it->missionID);

                for (int i = 0; i < missionTasksProgress.size(); ++i) {
                    missionTasksProgress.at(i) = std::to_string(std::stoi(missionTasksProgress.at(i)) + updateVal);

                    UpdateMissionTask(caster, playerObject, missionModel.missionID, 1 << (i + 1), std::stoi(missionTasksProgress.at(i)));
                }

                missionModel.progress = StringUtils::StringVectorToString(missionTasksProgress, '|');
                updateMissions.push_back(missionModel);
            }
            break;
        }
        case Enums::EMissionTask::EMOTE:
            break;
        case Enums::EMissionTask::SMASH_CHAIN:
            break;
        case Enums::EMissionTask::BUY:
            break;
        case Enums::EMissionTask::SELL:
            break;
        case Enums::EMissionTask::USE_ITEM:
            break;
        case Enums::EMissionTask::USE_SKILL:
            break;
        case Enums::EMissionTask::GATHER:
            break;
        case Enums::EMissionTask::EXPLORE:
            break;
        case Enums::EMissionTask::INVENTORY_CHANGE:
            break;
        case Enums::EMissionTask::MINIGAME_ACHIEVEMENT:
            break;
        case Enums::EMissionTask::INTERACT:
            break;
        case Enums::EMissionTask::MISSION_COMPLETE:
            break;
        case Enums::EMissionTask::REPUTATION:
            break;
        case Enums::EMissionTask::VOTING:
            break;
        case Enums::EMissionTask::SHOWCASE:
            break;
        case Enums::EMissionTask::HEAL:
            break;
        case Enums::EMissionTask::RECEIVE_CAST:
            break;
        case Enums::EMissionTask::TAME_PET:
            break;
        case Enums::EMissionTask::RACING:
            break;
        case Enums::EMissionTask::FLAG:
            break;
        case Enums::EMissionTask::PLACE_MODEL:
            break;
        case Enums::EMissionTask::REMOVE_MODEL:
            break;
        case Enums::EMissionTask::ADD_BEHAVIOR:
            break;
        case Enums::EMissionTask::REMOVE_BEHAVIOR:
            break;
        case Enums::EMissionTask::CLAIM_PROPERTY:
            break;
        case Enums::EMissionTask::PROPERTY_TRAVEL_TO:
            break;
        case Enums::EMissionTask::TIME_PLAYED:
            break;
        case Enums::EMissionTask::DONATE:
            break;
        case Enums::EMissionTask::UNKNOWN_33:
            break;
        case Enums::EMissionTask::UNKNOWN_34:
            break;
        case Enums::EMissionTask::TEAM:
            break;
        case Enums::EMissionTask::UNKNOWN_36:
            break;
        default:
            break;
        }
    
    }

    for (auto it = updateMissions.begin(); it != updateMissions.end(); ++it) {



        // Check if mission is done
        if (CheckIfMissionIsReadyToComplete(it->missionID, it->progress)) {
            if (it->state == 2 || it->state == 10) {
                it->state += 2;

                GM::NotifyMissionTask tMsg;
                tMsg.missionID = it->missionID;

            }

            /*
                Mission completion
            */

            GM::NotifyMission msg;
            msg.missionID = it->missionID;
            msg.missionState = 0;
            msg.sendingRewards = true;
            GameMessages::Send(playerObject, player, msg);

            // TODO: Send rewards

            msg.missionState = it->state;
            msg.sendingRewards = false;
            GameMessages::Send(Instance, Instance->sessionManager.GetSession(player)->systemAddress, player, msg);
        }

        Database::UpdateMission(*it);
    }
}

bool MissionManager::CheckIfMissionIsReadyToComplete(std::int32_t missionID, std::string &progress) {
    Database::MissionModel mm; mm.missionID; mm.progress = progress;
    auto mp = StringUtils::splitString(mm.progress, '|');

    std::int32_t rowIndex = 0;
    auto row = CacheMissionTasks::getRow(missionID);
    while (row.isValid()) {

        // Collectibles are handled differently
        if (CacheMissionTasks::GetTaskType(row) == 3) {
            std::int32_t sum = 0;
            std::int32_t targetVal = CacheMissionTasks::GetTargetValue(row);
            std::string progVal = *std::next(mp.begin(), rowIndex);
            if (StringUtils::splitString(progVal, ':').size() < targetVal) return false;
        }
        else {
            if (std::stoi(*std::next(mp.begin(), rowIndex)) < CacheMissionTasks::GetTargetValue(row)) return false;
        }

        if (!row.isLinkedRowInfoValid()) break;
        row = row.getLinkedRowInfo();
        ++rowIndex;
    }
    return true;
}
