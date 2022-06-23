#pragma once

namespace ecs
{
	using component_id = size_t;
	using entity_id = size_t;

	constexpr component_id max_components = 32;
	constexpr entity_id max_entities = 5000;
}
