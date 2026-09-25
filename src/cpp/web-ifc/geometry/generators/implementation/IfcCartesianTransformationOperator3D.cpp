#include <spdlog/spdlog.h>
#include "../generators.h"
namespace webifc::geometry::generators {
	glm::dmat4 GenerateIfcCartesianTransformationOperator3DImpl(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		if (!cacheOff) {
			auto cacheHit = cache.Get<glm::dmat4>(expressID);
			if (cacheHit.has_value()) return cacheHit->get();
		}
		spdlog::debug("[GenerateIfcCartesianTransformationOperator3DImpl({})]", expressID);
		double scale = 1.0;
        glm::dvec3 axis1(1, 0, 0);
        glm::dvec3 axis2(0, 1, 0);
        glm::dvec3 axis3(0, 0, 1);

        loader.MoveToArgumentOffset(expressID, 0);
        if (loader.GetTokenType() == parsing::IfcTokenType::REF)
        {
          loader.StepBack();
          axis1 = GenerateIfcDirection(loader.GetRefArgument(),lineType,loader,cache,settings);
        }
        
        loader.MoveToArgumentOffset(expressID, 1);
        if (loader.GetTokenType() == parsing::IfcTokenType::REF)
        {
          loader.StepBack();
          axis2 = GenerateIfcDirection(loader.GetRefArgument(),lineType,loader,cache,settings);
        }

        loader.MoveToArgumentOffset(expressID, 2);
        uint32_t localOriginID = loader.GetRefArgument();
        glm::dvec3 localOrigin = GenerateIfcCartesianPoint(localOriginID,lineType,loader,cache,settings);

        loader.MoveToArgumentOffset(expressID, 3);
        if (loader.GetTokenType() == parsing::IfcTokenType::REAL)
        {
          loader.StepBack();
          scale = loader.GetDoubleArgument();
        }

        loader.MoveToArgumentOffset(expressID, 4);
        if (loader.GetTokenType() == parsing::IfcTokenType::REF)
        {
          loader.StepBack();
          axis3 = GenerateIfcDirection(loader.GetRefArgument(),lineType,loader,cache,settings);
        }

        glm::dmat4 result = glm::dmat4(
            glm::dvec4(axis1 * scale, 0),
            glm::dvec4(axis2 * scale, 0),
            glm::dvec4(axis3 * scale, 0),
            glm::dvec4(localOrigin, 1));

		if (!cacheOff) cache.Cache(expressID,result);
		return result;
	}
}
