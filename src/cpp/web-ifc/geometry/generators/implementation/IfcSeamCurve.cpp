#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	std::vector<glm::dvec3> GenerateIfcSeamCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<std::vector<glm::dvec3>>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcSeamCurveImpl({})]", expressID);
		std::vector<glm::dvec3> result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
