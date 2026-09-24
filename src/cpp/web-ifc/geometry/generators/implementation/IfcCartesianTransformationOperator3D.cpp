#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dmat4 GenerateIfcCartesianTransformationOperator3DImpl(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<glm::dmat4>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcCartesianTransformationOperator3DImpl({})]", expressID);
		glm::dmat4 result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
