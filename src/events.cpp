#include "../include/events.hpp"

crs::Event::Event(const EventType &type) : type(type) {}

[[maybe_unused]] void crs::Cancelable::setCancelled(bool cancel) {
	Cancelable::cancelled = cancel;
}

[[maybe_unused]] bool crs::Cancelable::isCancelled() const {
	return Cancelable::cancelled;
}

[[maybe_unused]] crs::EventType crs::Event::getType() {
	return Event::type;
}

crs::QuitEvent::QuitEvent() : Event(QUIT) {}

[[maybe_unused]] crs::MoveEvent::MoveEvent(const Direction& direction, crs::Location* newLocation) : Event(MOVE), newLocation(newLocation), direction(direction) {}

[[maybe_unused]] crs::Location* crs::MoveEvent::getNewLocation() const {
	return MoveEvent::newLocation;
}

[[maybe_unused]] crs::Direction crs::MoveEvent::getDirection() const {
	return direction;
}

[[maybe_unused]] void crs::MoveEvent::setNewLocation(crs::Location* newLoc) {
	MoveEvent::newLocation = newLoc;
}

[[maybe_unused]] crs::CrossFoundEvent::CrossFoundEvent(const crs::Location& oldLoc, crs::Location* newLoc) : Event(CROSS_FOUND), oldCrossLocation(oldLoc), newCrossLocation(newLoc) {}

[[maybe_unused]] crs::Location crs::CrossFoundEvent::getOldCrossLocation() const {
	return CrossFoundEvent::oldCrossLocation;
}

[[maybe_unused]] crs::Location *crs::CrossFoundEvent::getNewCrossLocation() const {
	return CrossFoundEvent::newCrossLocation;
}

[[maybe_unused]] void crs::CrossFoundEvent::setNewCrossLocation(crs::Location* newLoc) {
	CrossFoundEvent::newCrossLocation = newLoc;
}

crs::CrossFoundEvent::~CrossFoundEvent() {
	delete CrossFoundEvent::newCrossLocation;
}
