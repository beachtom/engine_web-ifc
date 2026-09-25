#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dvec3 GenerateIfcCartesianPoint(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<glm::dvec3>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcCartesianPointImpl({})]", expressID);
		loader.MoveToArgumentOffset(expressID, 0);
    	loader.GetTokenType();
    	double x = loader.GetDoubleArgument();
    	double y = loader.GetDoubleArgument();
    	double z = loader.GetOptionalDoubleParam(0);
    	glm::dvec3 result(x, y, z);
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
