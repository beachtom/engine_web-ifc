#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dvec3 GenerateIfcVertexImpl(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<glm::dvec3>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcVertexImpl({})]", expressID);
		glm::dvec3 result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
