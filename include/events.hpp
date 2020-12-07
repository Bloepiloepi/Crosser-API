#ifndef CROSSERAPI_EVENTS_HPP
#define CROSSERAPI_EVENTS_HPP

#include "location.hpp"
#include "api-utils.hpp"

namespace crs {

	enum EventType {
		QUIT,
		MOVE,
		CROSS_FOUND
	};

	class Event {
		bool cancelled = false;
		const EventType type;

	protected:
		Event(const EventType &type);

	public:
		[[maybe_unused]] void setCancelled(bool cancel);
		[[maybe_unused]] [[nodiscard]] bool isCancelled() const;

		EventType getType();
	};

	class QuitEvent : public Event {
	public:
		QuitEvent();
	};

	class MoveEvent : public Event {
		const Direction direction;
		Location *newLocation;

	public:
		[[maybe_unused]] MoveEvent(const Direction& direction, Location& newLocation);

		[[maybe_unused]] [[nodiscard]] Location getNewLocation() const;
		[[maybe_unused]] [[nodiscard]] Direction getDirection() const;

		[[maybe_unused]] void setNewLocation(Location& newLoc);
	};

	class CrossFoundEvent : public Event {
		const Location oldCrossLocation;
		Location *newCrossLocation;

	public:
		[[maybe_unused]] CrossFoundEvent(const Location& oldLoc, Location* newLoc);

		[[maybe_unused]] [[nodiscard]] Location getOldCrossLocation() const;
		[[maybe_unused]] [[nodiscard]] Location *getNewCrossLocation() const;

		[[maybe_unused]] void setNewCrossLocation(Location newCrossLocation);
	};
}

#endif //CROSSERAPI_EVENTS_HPP
