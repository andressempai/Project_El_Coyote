#include "FollowNode.hpp"

#include <UnigineGame.h>

namespace ElCoyote {
	REGISTER_COMPONENT(FollowNode);

	void FollowNode::initialize() noexcept
	{
		if (!target_node_.isEmpty()) {
			node_reference_ptr_ = Unigine::dynamic_ptr_cast<Unigine::NodeReference>(target_node_.get());
		}
	}

	void FollowNode::update() noexcept
	{
		using namespace Unigine::Math;

		if (node_reference_ptr_) {
			const auto frame_time = Unigine::Game::getIFps();

			const auto target_world_position =
				node_reference_ptr_->getReference()->getChild(0)->getWorldPosition() + position_offset_;

			const auto node_world_positon = node->getWorldPosition();

			node->setWorldPosition(lerp(node_world_positon, target_world_position, smoothness_ * frame_time));
		}
	}
}