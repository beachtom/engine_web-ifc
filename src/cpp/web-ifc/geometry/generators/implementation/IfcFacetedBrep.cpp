#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	IfcGeometry GenerateIfcFacetedBrepImpl(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<IfcGeometry>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcFacetedBrepImpl({})]", expressID);
		IfcGeometry result;
		
		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
