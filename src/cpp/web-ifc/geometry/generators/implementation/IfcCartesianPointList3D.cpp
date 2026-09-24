#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	std::vector<glm::dvec3> GenerateIfcCartesianPointList3D(const uint32_t expressID, const uint32_t, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &) {
		auto cacheHit = cache.Get<std::vector<glm::dvec3>>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcCartesianPointList3DImpl({})]", expressID);
		std::vector<glm::dvec3> result;
		loader.MoveToArgumentOffset(expressID, 0);
		loader.GetTokenType();
		while (loader.GetTokenType() == parsing::IfcTokenType::SET_BEGIN)
    	{
      		double x = loader.GetDoubleArgument();
      		double y = loader.GetDoubleArgument();
      		double z = loader.GetDoubleArgument();
		    result.emplace_back(x, y, z);
		}
      	loader.GetTokenType();
		cache.Cache(expressID,result);
		return result;
	}
}
