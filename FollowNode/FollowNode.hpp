#pragma once
#include <UnigineComponentSystem.h>

namespace ElCoyote {
	class FollowNode final : public Unigine::ComponentBase {
		COMPONENT_DEFINE(FollowNode, Unigine::ComponentBase);
		COMPONENT_INIT(initialize);
		COMPONENT_UPDATE(update);

	private:
		void initialize() noexcept;
		void update() noexcept;

		PROP_PARAM(Node, target_node_, "Target Node");
		PROP_PARAM(Vec3, position_offset_, "Position Offset");
		PROP_PARAM(Float, smoothness_, 0.0f, "Smoothness");

		Unigine::NodeReferencePtr node_reference_ptr_{};
	};
}