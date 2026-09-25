#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	std::vector<glm::dvec3> GenerateIfcOrientedEdge(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<std::vector<glm::dvec3>>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcOrientedEdgeImpl({})]", expressID);
		std::vector<glm::dvec3> result;
		
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
