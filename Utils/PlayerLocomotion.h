#ifndef PLAYER_LOCOMOTION
#define PLAYER_LOCOMOTION

#include <UnigineComponentSystem.h>

struct PlayerLocomotion : Unigine::ComponentStruct {
	PROP_PARAM(Float, walk_speed_, 0.0f, "Walk Speed");
	PROP_PARAM(Float, boost_speed_, 0.0f, "Boost Speed");
	PROP_PARAM(Float, jump_speed_, 0.0f, "Jump Speed");
};

#endif	// !PLAYER_LOCOMOTION