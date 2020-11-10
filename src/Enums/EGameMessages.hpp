#ifndef __ENUMS__EGAMEMESSAGES_HPP__
#define __ENUMS__EGAMEMESSAGES_HPP__

namespace Enums {

	/*
		Enum that contains the IDs of all Game Messages.
		Prefixes:
		  CLIENT = Packets that are received by the server.
		  SERVER = Packets that are sent by the server.
		  DUAL = Both CLIENT and SERVER.
		  UNKNOWN = Packets that did not shown on the packet logs.
	*/
	enum EGameMessageID : unsigned short {
		SERVER_TELEPORT = 19,
		SET_PLAYER_CONTROL_SCHEME = 26,
		SERVER_DROP_CLIENT_LOOT = 30,
		SERVER_DIE = 37,
		CLIENT_REQUEST_DIE = 38,

		CLIENT_REQUEST_PLAY_EMOTE = 41,
		SERVER_PRELOAD_ANIMATION = 42,
		SERVER_PLAY_ANIMATION = 43,
		CLIENT_CONTROL_BEHAVIORS = 48,

		SERVER_SET_NAME = 72,
		PROXIMITY_UPDATE = 0x55,

		SERVER_START_SKILL = 118,
		CLIENT_REQUEST_START_SKILL = 119,
		CLIENT_CASTER_DEAD = 120,
		CLIENT_VERIFY_ACK = 121,
		CLIENT_SELECT_SKILL = 124,
		SERVER_ADD_SKILL = 127,
		SERVER_REMOVE_SKILL = 128,

		SERVER_SET_CURRENCY = 133,
		CLIENT_PICKUP_CURRENCY = 137,
		CLIENT_PICKUP_ITEM = 139,
		SERVER_TEAMMATE_PICKUP_ITEM = 140,

		SERVER_PLAY_FX = 154,
		SERVER_STOP_FX = 155,

		CLIENT_REQUEST_RESURRECT = 159,
		SERVER_RESURRECT = 160,

		CLIENT_POP_EQUIPPED_ITEMS_STATE = 192,
		SERVER_SET_STUNNED = 198,
		SERVER_SET_STUNNED_IMMUNITY = 200,
		SERVER_KNOCKBACK = 202,

		CLIENT_CANCEL_REBUILD = 209,
		SERVER_ENABLE_REBUILD = 213,

		DUAL_MOVE_ITEM_IN_INVENTORY = 224,
		SERVER_ADD_ITEM_TO_INVENTORY_CLIENT_SYNC = 227,
		DUAL_REMOVE_ITEM_FROM_INVENTORY = 230,
		DUAL_EQUIP_ITEM = 231,
		DUAL_UNEQUIP_ITEM = 233,

		SERVER_OFFER_MISSION = 248,
		CLIENT_RESPOND_TO_MISSION = 249,
		SERVER_NOTIFY_MISSION = 254,
		SERVER_NOTIFY_MISSION_TASK = 255,


		SERVER_REBUILD_NOTIFY_STATE = 336,
		SERVER_TOGGLE_INTERACTION_UPDATES = 356,
		CLIENT_TERMINATE_INTERACTION = 357,
		SERVER_TERMINATE_INTERACTION = 358,

		CLIENT_REQUEST_USE = 364,
		SERVER_OPEN_VENDOR_WINDOW = 369,
		SERVER_EMOTE_PLAYED = 371,
		CLIENT_BUY_FROM_VENDOR = 373,
		CLIENT_SELL_TO_VENDOR = 374,

		CLIENT_CANCEL_DONATION_ON_PLAYER = 379,
		// Teammate left world?
		SERVER_TEAM_SET_OFF_WORLD_FLAG = 383,
		SERVER_SET_INVENTORY_SIZE = 389,
		CLIENT_ACKNOWLEDGE_POSSESSION = 391,

		CLIENT_REQUEST_ACTIVITY_EXIT = 404,
		SERVER_ACTIVITY_ENTER = 405,
		SERVER_ACTIVITY_EXIT = 406,
		SERVER_ACTIVITY_START = 407,
		SERVER_ACTIVITY_STOP = 408,

		CLIENT_SHOOTING_GALLERY_FIRE = 411,
		CLIENT_REQUEST_VENDOR_STATUS_UPDATE = 416,
		SERVER_LIST_VENDOR_ITEMS = 417,
		SERVER_CANCEL_MISSION = 418,
		SERVER_RESET_MISSION = 419,
		SERVER_NOTIFY_SHOOTING_GALLERY_SCORE = 425,
		CLIENT_CONSUMED_ITEM = 428,
		CLIENT_UPDATE_SHOOTING_GALLERY_ROTATION = 448,

		// Suspected server packet
		UNKNOWN_SET_USER_CTRL_COMP_PAUSE = 466,
		CLIENT_SET_TOOLTIP_FLAG = 469,
		CLIENT_SET_FLAG = 471,
		SERVER_SET_FLAG = 472,
		SERVER_HELP = 475,
		SERVER_VENDOR_TRANSACTION_RESULT = 476,

		// When a player collects something
		CLIENT_HAS_BEEN_COLLECTED = 486,
		// To notify a player when another player collects something?
		SERVER_HAS_BEEN_COLLECTED_BY_CLIENT = 487,
		CLIENT_DESPAWN_PET = 499,
		CLIENT_PLAYER_LOADED = 505,
		SERVER_PLAYER_READY = 509,

		CLIENT_REQUEST_LINKED_MISSION = 515,
		SERVER_TRANSFER_TO_ZONE = 516,
		SERVER_TRANSFER_TO_ZONE_CHECKED_IM = 517,
		SERVER_INVALID_ZONE_TRANSFER_LIST = 519,
		CLIENT_MISSION_DIALOGUE_OK = 520,
		SERVER_TRANSFER_TO_LAST_NON_INSTANCE = 527,

		SERVER_DISPLAY_MESSAGE_BOX = 529,
		CLIENT_MESSAGE_BOX_RESPOND = 530,
		CLIENT_CHOICE_BOX_RESPOND = 531,

		SERVER_SMASH = 537,
		SERVER_UNSMASH = 538,

		SERVER_SET_GRAVITY_SCALE = 541,
		SERVER_PLACE_MODEL = 547,
		SERVER_SET_JETPACK_MODE = 561,

		SERVER_REGISTER_PET_ID = 565,
		SERVER_REGISTER_PET_DBID = 566,

		SERVER_SHOW_ACTIVITY_COOLDOWN = 568,
		// Suspected server packet
		UNKNOWN_DISPLAY_TOOLTIP = 569,
		SERVER_START_ACTIVITY_TIME = 576,
		SERVER_ACTIVITY_PAUSE = 602,

		CLIENT_USE_NON_EQUIPMENT_ITEM = 603,
		SERVER_USED_ITEM_RESULT = 607,
		CLIENT_FETCH_MODEL_METADATA = 638,

		CLIENT_COMMAND_PET = 640,
		SERVER_PET_RESPONSE = 641,

		CLIENT_REQUEST_ACTIVITY_SUMMARY_LEADERBOARD_DATA = 648,
		SERVER_SEND_ACTIVITY_SUMMARY_LEADERBOARD_DATA = 649,

		SERVER_NOTIFY_PET = 659,
		CLIENT_NOTIFY_PET = 660,

		SERVER_NOTIFY_PET_TAMING_MINIGAME = 661,
		CLIENT_START_PET_MINIGAME_TIMER = 662,
		CLIENT_EXIT_TAMING_MINIGAME = 663,
		CLIENT_PET_TAMING_MINIGAME_RESULT = 667,

		SERVER_PET_TAMING_TRY_BUILD_RESULT = 668,
		CLIENT_NOTIFY_TAMING_BUILD_SUCCESS = 673,
		SERVER_NOTIFY_TAMING_MODEL_LOADED_ON_SERVER = 674,
		DUAL_NOTIFY_PET_TAMING_PUZZLE_SELECTED = 675,
		SERVER_ADD_PET_TO_PLAYER = 681,

		CLIENT_REQUEST_SET_PET_NAME = 683,
		SERVER_SET_PET_NAME = 684,
		SERVER_PET_NAME_CHANGED = 686,
		SERVER_SHOW_PET_ACTION_BUTTON = 692,
		SERVER_SET_EMOTE_LOCK_STATE = 693,

		UNKNOWN_USE_ITEM_REQUIREMENTS_RESPONSE = 703,
		SERVER_PLAY_EMBEDDED_EFFECT_ON_ALL_NEARBY_CLIENTS = 713,

		CLIENT_QUERY_PROPERTY_DATA = 717,
		CLIENT_PROPERTY_EDITOR_BEGIN = 724,
		CLIENT_PROPERTY_EDITOR_END = 725,

		SERVER_NOTIFY_CLIENT_ZONE_OBJECT = 737,
		SERVER_UPDATE_REPUTATION = 746,
		SERVER_PROPERTY_RENTAL_RESPONSE = 750,

		CLIENT_REQUEST_PLATFORM_RESYNC = 760,
		SERVER_PLATFORM_RESYNC = 761,

		SERVER_PLAY_CINEMATIC = 762,
		SERVER_END_CINEMATIC = 763,
		CLIENT_CINEMATIC_UPDATE = 764,

		CLIENT_TOGGLE_GHOST_REFERENCE_OVERRIDE = 767,
		CLIENT_SET_GHOST_REFERENCE_POSITION = 768,

		CLIENT_REQUEST_SMASH_PLAYER = 0x4b2,

		CLIENT_FIRE_EVENT_SERVER_SIDE = 770,
		SERVER_SCRIPT_NETWORK_VAR_UPDATE = 781,

		CLIENT_UPDATE_MODEL = 793,
		CLIENT_DELETE_MODEL = 794,

		SERVER_PLAY_AUDIO_EMITTER = 821,
		// Suspected server packet
		UNKNOWN_STOP_AUDIO_EMITTER = 822,

		CLIENT_ENTER_PROPERTY = 840,
		CLIENT_PROPERTY_ENTRANCE_SYNC = 842,

		CLIENT_PARSE_CHAT_MESSAGE = 850,
		CLIENT_SET_MISSION_TYPE_STATE = 851,
		SERVER_BROADCAST_TEXT_TO_CHATBOX = 858,
		SERVER_OPEN_PROPERTY_VENDOR = 861,

		// Below are many packets that deal with trading . .
		// most of them didn't show up in the capture logs
		UNKNOWN_CLIENT_TRADE_REQUEST = 868,
		UNKNOWN_SEND_TRADE_INVITE = 870,
		UNKNOWN_SERVER_TRADE_INITIAL_REPLY = 873,
		UNKNOWN_SERVER_TRADE_FINAL_REPLY = 874,
		CLIENT_TRADE_CANCEL = 878,
		UNKNOWN_CLIENT_TRADE_ACCEPT = 880,
		UNKNOWN_SERVER_TRADE_ACCEPT = 884,

		CLIENT_READY_FOR_UPDATES = 888,
		CLIENT_SET_LAST_CUSTOM_BUILD = 890,
		SERVER_GET_LAST_CUSTOM_BUILD = 891,
		SERVER_SET_IGNORE_PROJECTILE_COLLISION = 903,

		SERVER_ORIENT_TO_OBJECT = 905,
		SERVER_ORIENT_TO_POSITION = 906,
		SERVER_ORIENT_TO_ANGLE = 907,

		CLIENT_PROPERTY_MODERATION_ACTION = 915,
		SERVER_PROPERTY_MODERATION_STATUS_UPDATE = 917,

		CLIENT_BOUNCE_NOTIFICATION = 932,
		SERVER_REQUEST_CLIENT_BOUNCE = 934,
		SERVER_BOUNCER_ACTIVE_STATUS = 942,

		DUAL_MOVE_INVENTORY_BATCH = 957,
		UNKNOWN_OBJECT_ACTIVATED_CLIENT = 980,

		CLIENT_SET_BBB_AUTOSAVE = 996,
		CLIENT_BBB_LOAD_ITEM_REQUEST = 1000,
		CLIENT_BBB_SAVE_REQUEST = 1001,
		CLIENT_BBB_RESET_METADATA_SOURCE_ITEM = 1004,

		SERVER_NOTIFY_CLIENT_OBJECT = 1042,
		SERVER_DISPLAY_ZONE_SUMMARY = 1043,
		CLIENT_ZONE_SUMMARY_DISMISSED = 1044,
		DUAL_MODIFY_PLAYER_ZONE_STATISTICS = 1046,

		CLIENT_ACTIVITY_STATE_CHANGE_REQUEST = 1053,

		CLIENT_START_BUILDING_WITH_ITEM = 1057,
		SERVER_START_ARRANGING_WITH_ITEM = 1061,
		SERVER_FINISH_ARRANGING_WITH_ITEM = 1062,
		CLIENT_DONE_ARRANGING_WITH_ITEM = 1063,

		CLIENT_SET_BUILD_MODE = 1068,
		CLIENT_BUILD_MODE_SET = 1069,
		CLIENT_BUILD_EXIT_CONFIRMATION = 1072,
		SERVER_BUILD_MODE_CONFIRMED = 1073,
		SERVER_BUILD_MODE_NOTIFICATION_REPORT = 1075,

		SERVER_SETMODEL_TO_BUILD = 1077,
		SERVER_SPAWN_MODEL_BRICKS = 1078,

		// Suspected server packet
		UNKNOWN_NOTIFY_CLIENT_FAILED_PRECONDITION = 1081,
		CLIENT_MODULAR_BUILD_WITH_EQUIPPED = 1090,
		CLIENT_MOVE_ITEM_BETWEEN_INVENTORY_TYPES = 1093,
		CLIENT_MODULAR_BUILD_MOVE_AND_EQUIP = 1096,
		CLIENT_MODULAR_BUILD_FINISH = 1097,

		ARRIVED_AT_DESIRED_WAYPOINT = 0x45c,

		CLIENT_MISSION_DIALOGUE_CANCELLED = 1129,

		SERVER_MODULE_ASSEMBLY_DBDATA_FOR_CLIENT = 1131,
		CLIENT_MODULE_ASSEMBLY_QUERY_DATA = 1132,

		SERVER_SYNC_SKILL = 1144,
		CLIENT_SYNC_SKILL = 1145,

		CLIENT_REQUEST_SERVER_PROJECTILE_IMPACT = 1148,
		SERVER_DO_CLIENT_PROJECTILE_IMPACT = 1151,
		CLIENT_EDIT_COMPLETED_MODULE = 1155,

		SERVER_SET_PLAYER_ALLOWED_RESPAWN = 1165,
		CLIENT_TOGGLE_SENDING_POSITION_UPDATES = 1166,
		CLIENT_PLACE_PROPERTY_MODEL = 1170,
		SERVER_UI_MESSAGE_TO_SINGLE_CLIENT = 1184,
		CLIENT_PET_TAMING_TRY_BUILD = 1197,
		CLIENT_HELPMENU_REQUEST_HELP = 1198,
		CLIENT_HELPMENU_SMASH = 1202,

		SERVER_UNCAST_SKILL = 1206,
		SERVER_FIRE_CLIENT_EVENT = 1213,
		SERVER_CHANGE_OBJECT_WORLD_STATE = 1223,
		SERVER_VEHICLE_LOCK_INPUT = 1230,

		SERVER_VEHICLE_UNLOCK_INPUT = 1231,
		CLIENT_RESYNC_EQUIPMENT = 1238,
		SERVER_RACING_RESET_PLAYER_TO_LAST_RESET = 1252,
		SERVER_RACING_SET_PLAYER_RESET_INFO = 1254,

		CLIENT_RACING_PLAYER_INFO_RESET_FINISHED = 1255,
		SERVER_LOCK_NODE_ROTATION = 1260,
		CLIENT_VEHICLE_SET_WHEEL_LOCK_STATE = 1273,
		SERVER_NOTIFY_VEHICLE_OF_RACING_OBJECT = 1276,

		SERVER_PLAYER_REACHED_RESPAWN_CHECKPOINT = 1296,
		SERVER_HANDLE_UGC_EQUIP_POST_DELETE = 1300,
		SERVER_HANDLE_UGC_EQUIP_PRE_CREATE = 1301,
		CLIENT_PROPERTY_CONTENTS = 1305,

		SERVER_MATCH_RESPONSE = 1309,
		SERVER_MATCH_UPDATE = 1310,
		SERVER_CHANGE_IDLE_FLAGS = 1338,

		SERVER_VEHICLE_ADD_PASSIVE_BOOST_ACTION = 1340,
		SERVER_VEHICLE_REMOVE_PASSIVE_BOOST_ACTION = 1341,
		CLIENT_VEHICLE_NOTIFY_SERVER_ADD_PASSIVE_BOOST_ACTION = 1342,
		CLIENT_VEHICLE_NOTIFY_SERVER_REMOVE_PASSIVE_BOOST_ACTION = 1343,

		CLIENT_BUY_BACK_FROM_VENDOR = 1350,

		CLIENT_ZONE_PROPERTY_MODEL_ROTATED = 1370,
		CLIENT_ZONE_PROPERTY_MODEL_REMOVED_WHILE_EQUIPPED = 1371,
		CLIENT_ZONE_PROPERTY_MODEL_EQUIPPED = 1372,

		SERVER_NOTIFY_RACING_CLIENT = 1390,
		SERVER_RACING_PLAYER_LOADED = 1392,
		CLIENT_RACING_READY = 1393,

		CLIENT_RESET_PROPERTY_BEHAVIORS = 1406,
		CLIENT_SET_CONSUMABLE_ITEM = 1409,
		CLIENT_USED_INFORMATION_PLAQUE = 1419,

		SERVER_SET_STATUS_IMMUNITY = 1435,
		CLIENT_ACTIVATED_BRICK_MODE = 1438,
		SERVER_SET_PET_NAME_MODERATED = 1448,
		SERVER_CANCEL_SKILL_CAST = 1451,

		SERVER_MODIFY_LEGO_SCORE = 1459,
		SERVER_RESTORE_TO_POST_LOAD_STATS = 1468,

		// Suspected server packet
		UNKNOWN_SET_RAIL_MOVEMENT = 1471,
		// Suspected server packet
		UNKNOWN_START_RAIL_MOVEMENT = 1472,
		CLIENT_CANCEL_RAIL_MOVEMENT = 1474,
		// Suspected client packet
		UNKNOWN_CLIENT_RAIL_MOVEMENT_READY = 1476,
		// Suspected server packet, known server packets have the word "Notification" in them
		UNKNOWN_PLAYER_RAIL_ARRIVED_NOTIFICATION = 1477,
		// Suspected server packet
		UNKNOWN_NOTIFY_RAIL_ACTIVATOR_STATE_CHANGE = 1478,
		// Suspected client packet
		UNKNOWN_REQUEST_RAIL_ACTIVATOR_STATE = 1479,

		SERVER_NOTIFY_REWARD_MAILED = 1480,
		SERVER_UPDATE_PLAYER_STATISTIC = 1481,
		CLIENT_MODIFY_GHOSTING_DISTANCE = 1485,
		SERVER_REQUERY_PROPERTY_MODELS = 1491,

		CLIENT_MODULAR_ASSEMBLY_NIF_COMPLETED = 1498,
		CLIENT_GET_HOT_PROPERTY_DATA = 1511,
		SERVER_NOTIFY_NOT_ENOUGH_INV_SPACE = 1516,

		SERVER_NOTIFY_PROPERTY_OF_EDIT_MODE = 1546,
		CLIENT_UPDATE_PROPERTY_PERFORMANCE_COST = 1547,
		SERVER_PROPERTY_ENTRANCE_BEGIN = 1553,

		SERVER_TEAM_SET_LEADER = 1557,
		SERVER_TEAM_INVITE_CONFIRM = 1558,
		SERVER_TEAM_GET_STATUS_RESPONSE = 1559,
		SERVER_TEAM_ADD_PLAYER = 1562,
		SERVER_TEAM_REMOVE_PLAYER = 1563,

		CLIENT_SET_EMOTES_ENABLED = 1577,
		SERVER_SET_RESURRECT_RESTORE_VALUES = 1591,
		SERVER_SET_PROPERTY_MODERATION_STATUS = 1594,
		SERVER_UPDATE_PROPERTY_MODEL_COUNT = 1595,

		CLIENT_VEHICLE_NOTIFY_HIT_IMAGINATION_SERVER = 1606,
		SERVER_VEHICLE_STOP_BOOST = 1617,
		SERVER_START_CELEBRATION_EFFECT = 1618,
		CLIENT_CELEBRATION_COMPLETED = 1632,

		SERVER_SET_LOCAL_TEAM = 1636,
		SERVER_DONE_LOADING_ALL_OBJECTS = 1642,
		SERVER_ADD_BUFF = 1647,
		SERVER_REMOVE_BUFF = 1648,

		SERVER_SET_PLAYER_CAMERA_CYCLING_MODE = 1676,
		SERVER_SET_MOUNT_INVENTORY_ID = 1726,
		CLIENT_NOTIFY_SERVER_LEVEL_PROCESSING_COMPLETE = 1734,

		UNKNOWN_SERVER_CANCEL_MOVE_SKILL = 1746,
		SERVER_CLIENT_CANCEL_MOVE_SKILL = 1747,

		CLIENT_DISMOUNT_COMPLETE = 1756,
		SERVER_MARK_INVENTORY_ITEM_AS_ACTIVE = 1767,

		// Todo : .
		//    1)  Check to make sure they're all correct
	};
}

#endif // !__ENUMS__EGAMEMESSAGES_HPP__
