#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dmat3 GenerateIfcCartesianTransformationOperator2DImpl(const uint32_t expressID, const uint32_t, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, const bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<glm::dmat2>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcCartesianTransformationOperator2DImpl({})]", expressID);
		
		double scale = 1.0;
    	glm::dvec3 axis1(1, 0, 0);
    	glm::dvec3 axis2(0, 1, 0);
 
 		loader.MoveToArgumentOffset(expressID, 0);
    	if (loader.GetTokenType() == parsing::IfcTokenType::REF) {
      		loader.StepBack();
      		axis1 = GenerateIfcDirection(loader.GetRefArgument(),lineType,loader,cache,settings);
    	}
    
    	loader.MoveToArgumentOffset(expressID, 1);
    	if (loader.GetTokenType() == parsing::IfcTokenType::REF) {
      		loader.StepBack();
      		axis2 = GenerateIfcDirection(loader.GetRefArgument(),lineType,loader,cache,settings);
    	}

    	loader.MoveToArgumentOffset(expressID, 2);
    	uint32_t localOriginID = loader.GetRefArgument();
    	glm::dvec2 localOrigin = GenerateIfcCartesianPoint(localOriginID,lineType,loader,cache,settings);

    	loader.MoveToArgumentOffset(expressID, 3);
    	if (loader.GetTokenType() == parsing::IfcTokenType::REAL)
    	{
      		loader.StepBack();
      		scale = loader.GetDoubleArgument();
    	}

   		glm::dmat3 result = glm::dmat4(
        	glm::dvec2(axis1 * scale, 0),
        	glm::dvec2(axis2 * scale, 0),
        	glm::dvec2(localOrigin, 1)
        );

		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
