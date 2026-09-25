#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dvec3 GenerateIfcDirection(const uint32_t expressID, const uint32_t, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, const bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<glm::dvec3>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcDirectionImpl({})]", expressID);
		glm::dvec3 result = GenerateIfcCartesianPoint(expressID,lineType,loader,cache,settings,true);
		result = glm::normalize(result);
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
