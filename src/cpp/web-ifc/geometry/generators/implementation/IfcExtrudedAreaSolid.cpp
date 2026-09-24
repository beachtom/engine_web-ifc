#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	IfcGeometry GenerateIfcExtrudedAreaSolidImpl(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings) {
		auto cacheHit = cache.Get<IfcGeometry>(expressID);
		if (cacheHit.has_value()) return cacheHit->get();
		spdlog::debug("[GenerateIfcExtrudedAreaSolidImpl({})]", expressID);
		IfcGeometry result;
		
		cache.Cache(expressID,result);
		return result;
	}
}
