#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include <UnigineComponentSystem.h>
#include <UnigineMesh.h>
#include <UniginePhysics.h>

#include "../Utils/PlayerLocomotion.h"

class PlayerController final : public Unigine::ComponentBase {
	enum {
			idle		= 0b0000
		,	walk_right	= 0b0001
		,	walk_left	= 0b0010
		,	jump		= 0b0100
		,	boost		= 0b1000
	};

	COMPONENT_DEFINE(PlayerController, Unigine::ComponentBase);
	COMPONENT_DESCRIPTION("Player Controller Component");
	COMPONENT_INIT(initialize);
	COMPONENT_UPDATE(update);
	COMPONENT_UPDATE_PHYSICS(update_physics);

private:
	void initialize() noexcept;
	void update() noexcept;
	void update_physics() noexcept;

	PROP_STRUCT(PlayerLocomotion, player_locomotion_, "Player Locomotion");

	Unigine::ObjectMeshSkinnedPtr mesh_skinned_ptr_{ nullptr };
	Unigine::BodyRigidPtr body_rigid_ptr_{ nullptr };

	unsigned inputs_flags_{};
};

#endif	// !PLAYER_CONTROLLER