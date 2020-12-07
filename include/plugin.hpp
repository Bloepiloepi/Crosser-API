#ifndef CROSSERAPI_PLUGIN_HPP
#define CROSSERAPI_PLUGIN_HPP

#include "events.hpp"

namespace crs {

	class IPlugin {
	public:
		int id;

		virtual ~IPlugin() = default;

		virtual void setup() = 0;
		virtual void end() = 0;

		virtual void onEvent(crs::Event* &event) = 0;
	};
}

#endif //CROSSERAPI_PLUGIN_HPP
