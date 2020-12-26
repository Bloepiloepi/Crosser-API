#ifndef CROSSERAPI_IGAME_HPP
#define CROSSERAPI_IGAME_HPP

#include "api-utils.hpp"
#include "location.hpp"
#include <SFML/Graphics.hpp>

namespace crs {

	class IGame {
	public:
		[[nodiscard]] virtual bool isGameOver() const = 0;
		[[nodiscard]] virtual int getScore() const = 0;
		[[nodiscard]] virtual sf::Font getMainFont() const = 0;

		virtual void setZoom(float zoom) = 0;
		virtual void setFruitLocation(Location *location) = 0;
		virtual bool movePlayer(crs::Direction direction) = 0;

		virtual void setTileType(const Location& location, TileType type) = 0;
		virtual TileType getTileType(const Location& location) = 0;
	};
}

#endif //CROSSERAPI_IGAME_HPP
