#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	std::vector<glm::dvec3> GenerateIfcSurfaceOfRevolution(const uint32_t expressID, const uint32_t, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, const bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<std::vector<glm::dvec3>>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcSurfaceOfRevolutionImpl({})]", expressID);
		std::vector<glm::dvec3> result;
		
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
