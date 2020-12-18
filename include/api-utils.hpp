#ifndef CROSSERAPI_API_UTILS_HPP
#define CROSSERAPI_API_UTILS_HPP

namespace crs {
	enum Direction {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		AUTO
	};

	enum TileType {
		AIR,
		PLAYER,
		FRUIT,
		OBSTACLE,
		VISITED
	};
}

#endif //CROSSERAPI_API_UTILS_HPP
