#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dvec3 GenerateIfcPointOnCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<glm::dvec3>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcPointOnCurveImpl({})]", expressID);
		glm::dvec3 result;
		
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
