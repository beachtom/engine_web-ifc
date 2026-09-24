#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dvec4 GenerateIfcLightSourceSpot(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<glm::dvec4>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcLightSourceSpotImpl({})]", expressID);
		glm::dvec4 result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
