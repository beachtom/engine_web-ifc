#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	std::vector<glm::dvec2> GenerateIfcCartesianPointList2D(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<std::vector<glm::dvec2>>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcCartesianPointList2DImpl({})]", expressID);
		std::vector<glm::dvec2> result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
