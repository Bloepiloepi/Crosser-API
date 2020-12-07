#ifndef CROSSERAPI_LOCATION_HPP
#define CROSSERAPI_LOCATION_HPP

namespace crs {
	class Location {
		const int x;
		const int y;

	public:
		Location(int x, int y);
		Location(Location const &loc);

		[[nodiscard]] int getX() const;
		[[nodiscard]] int getY() const;
	};
}

#endif //CROSSERAPI_LOCATION_HPP
