#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	IfcGeometry GenerateIfcOpenShell(const uint32_t expressID, const uint32_t, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, const bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<IfcGeometry>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcOpenShellImpl({})]", expressID);
		IfcGeometry result;
		
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
