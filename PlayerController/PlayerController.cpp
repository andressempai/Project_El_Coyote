#include "PlayerController.h"

#include <UnigineControls.h>

REGISTER_COMPONENT(PlayerController);

void PlayerController::initialize() noexcept
{
	if (mesh_skinned_ptr_ = Unigine::dynamic_ptr_cast<Unigine::ObjectMeshSkinned>(node)) {
		body_rigid_ptr_ = mesh_skinned_ptr_->getBodyRigid();
	}
}

void PlayerController::update() noexcept
{
	inputs_flags_ = idle;

	if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_MOVE_RIGHT))
		inputs_flags_ = walk_right;
	
	if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_MOVE_LEFT))
		inputs_flags_ = walk_left;
	
	if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_JUMP))
		inputs_flags_ |= jump;

	if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_RUN))
		inputs_flags_ |= boost;
}

void PlayerController::update_physics() noexcept
{
	const auto movement_speed = [this]() noexcept
	{
		if (inputs_flags_ & boost)
			return player_locomotion_->boost_speed_;

		return player_locomotion_->walk_speed_;
	}();

	if (inputs_flags_ & walk_right)
		body_rigid_ptr_->addLinearImpulse(Unigine::Math::vec3_left * movement_speed);
	
	if (inputs_flags_ & walk_left)
		body_rigid_ptr_->addLinearImpulse(Unigine::Math::vec3_right * movement_speed);
	
	if (inputs_flags_ & jump)
		body_rigid_ptr_->addLinearImpulse(Unigine::Math::vec3_up * player_locomotion_.get().jump_speed_);
}