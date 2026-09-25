#include "generators.h"
namespace webifc::geometry::generators {
std::variant<glm::dvec3,IfcGeometry,std::vector<glm::dvec3>> GenerateIfcTopologicalRepresentationItem(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCVERTEX:
				return GenerateIfcVertex(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCONNECTEDFACESET:
				return GenerateIfcConnectedFaceSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCEDGE:
				return GenerateIfcEdge(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFACE:
				return GenerateIfcFace(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFACEBOUND:
				return GenerateIfcFaceBound(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCLOOP:
				return GenerateIfcLoop(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPATH:
				return GenerateIfcPath(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::variant<glm::dvec3,IfcGeometry,std::vector<glm::dvec3>> result;
	return result;
	}
glm::dvec3 GenerateIfcVertex(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCVERTEXPOINT:
				return GenerateIfcVertexPoint(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcVertexImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcConnectedFaceSet(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCOPENSHELL:
				return GenerateIfcOpenShell(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCLOSEDSHELL:
				return GenerateIfcClosedShell(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcConnectedFaceSetImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcEdge(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCEDGECURVE:
				return GenerateIfcEdgeCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCORIENTEDEDGE:
				return GenerateIfcOrientedEdge(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSUBEDGE:
				return GenerateIfcSubedge(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcEdgeImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcFace(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCFACESURFACE:
				return GenerateIfcFaceSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcFaceImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcFaceSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCADVANCEDFACE:
				return GenerateIfcAdvancedFace(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcFaceSurfaceImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcFaceBound(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCFACEOUTERBOUND:
				return GenerateIfcFaceOuterBound(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcFaceBoundImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcLoop(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCPOLYLOOP:
				return GenerateIfcPolyLoop(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCVERTEXLOOP:
				return GenerateIfcVertexLoop(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCEDGELOOP:
				return GenerateIfcEdgeLoop(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcLoopImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::variant<IfcGeometry,glm::dvec4,glm::dmat4,std::vector<glm::dvec3>,glm::dvec3,std::vector<glm::dvec2>,glm::dmat2> GenerateIfcGeometricRepresentationItem(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCGEOMETRICSET:
				return GenerateIfcGeometricSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCHALFSPACESOLID:
				return GenerateIfcHalfSpaceSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCLIGHTSOURCE:
				return GenerateIfcLightSource(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPLACEMENT:
				return GenerateIfcPlacement(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPLANAREXTENT:
				return GenerateIfcPlanarExtent(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOINT:
				return GenerateIfcPoint(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSECTIONEDSPINE:
				return GenerateIfcSectionedSpine(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSEGMENT:
				return GenerateIfcSegment(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSHELLBASEDSURFACEMODEL:
				return GenerateIfcShellBasedSurfaceModel(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSOLIDMODEL:
				return GenerateIfcSolidModel(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSURFACE:
				return GenerateIfcSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCTESSELLATEDITEM:
				return GenerateIfcTessellatedItem(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCTEXTLITERAL:
				return GenerateIfcTextLiteral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCVECTOR:
				return GenerateIfcVector(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCANNOTATIONFILLAREA:
				return GenerateIfcAnnotationFillArea(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBOOLEANRESULT:
				return GenerateIfcBooleanResult(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBOUNDINGBOX:
				return GenerateIfcBoundingBox(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCARTESIANPOINTLIST:
				return variant_cast<std::variant<IfcGeometry,glm::dvec4,glm::dmat4,std::vector<glm::dvec3>,glm::dvec3,std::vector<glm::dvec2>,glm::dmat2>>(GenerateIfcCartesianPointList(expressID,lineType,loader,cache,settings,cacheOff));
				break;
			 case webifc::schema::IFCCARTESIANTRANSFORMATIONOPERATOR:
				return variant_cast<std::variant<IfcGeometry,glm::dvec4,glm::dmat4,std::vector<glm::dvec3>,glm::dvec3,std::vector<glm::dvec2>,glm::dmat2>>(GenerateIfcCartesianTransformationOperator(expressID,lineType,loader,cache,settings,cacheOff));
				break;
			 case webifc::schema::IFCCSGPRIMITIVE3D:
				return GenerateIfcCsgPrimitive3D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCURVE:
				return GenerateIfcCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCDIRECTION:
				return GenerateIfcDirection(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFACEBASEDSURFACEMODEL:
				return GenerateIfcFaceBasedSurfaceModel(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFILLAREASTYLEHATCHING:
				return GenerateIfcFillAreaStyleHatching(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFILLAREASTYLETILES:
				return GenerateIfcFillAreaStyleTiles(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::variant<IfcGeometry,glm::dvec4,glm::dmat4,std::vector<glm::dvec3>,glm::dvec3,std::vector<glm::dvec2>,glm::dmat2> result;
	return result;
	}
IfcGeometry GenerateIfcGeometricSet(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCGEOMETRICCURVESET:
				return GenerateIfcGeometricCurveSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcGeometricSetImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcHalfSpaceSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCPOLYGONALBOUNDEDHALFSPACE:
				return GenerateIfcPolygonalBoundedHalfSpace(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBOXEDHALFSPACE:
				return GenerateIfcBoxedHalfSpace(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcHalfSpaceSolidImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
glm::dvec4 GenerateIfcLightSource(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCLIGHTSOURCEAMBIENT:
				return GenerateIfcLightSourceAmbient(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCLIGHTSOURCEDIRECTIONAL:
				return GenerateIfcLightSourceDirectional(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCLIGHTSOURCEGONIOMETRIC:
				return GenerateIfcLightSourceGoniometric(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCLIGHTSOURCEPOSITIONAL:
				return GenerateIfcLightSourcePositional(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	glm::dvec4 result;
	return result;
	}
glm::dvec4 GenerateIfcLightSourcePositional(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCLIGHTSOURCESPOT:
				return GenerateIfcLightSourceSpot(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcLightSourcePositionalImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
glm::dmat4 GenerateIfcPlacement(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCAXIS1PLACEMENT:
				return GenerateIfcAxis1Placement(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCAXIS2PLACEMENT2D:
				return GenerateIfcAxis2Placement2D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCAXIS2PLACEMENT3D:
				return GenerateIfcAxis2Placement3D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCAXIS2PLACEMENTLINEAR:
				return GenerateIfcAxis2PlacementLinear(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	glm::dmat4 result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcPlanarExtent(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCPLANARBOX:
				return GenerateIfcPlanarBox(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcPlanarExtentImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
glm::dvec3 GenerateIfcPoint(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCPOINTBYDISTANCEEXPRESSION:
				return GenerateIfcPointByDistanceExpression(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOINTONCURVE:
				return GenerateIfcPointOnCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOINTONSURFACE:
				return GenerateIfcPointOnSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCARTESIANPOINT:
				return GenerateIfcCartesianPoint(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	glm::dvec3 result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcSegment(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCOMPOSITECURVESEGMENT:
				return GenerateIfcCompositeCurveSegment(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCURVESEGMENT:
				return GenerateIfcCurveSegment(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcCompositeCurveSegment(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCREPARAMETRISEDCOMPOSITECURVESEGMENT:
				return GenerateIfcReparametrisedCompositeCurveSegment(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcCompositeCurveSegmentImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcSolidModel(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCSWEPTAREASOLID:
				return GenerateIfcSweptAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSWEPTDISKSOLID:
				return GenerateIfcSweptDiskSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCSGSOLID:
				return GenerateIfcCsgSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCMANIFOLDSOLIDBREP:
				return GenerateIfcManifoldSolidBrep(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSECTIONEDSOLID:
				return GenerateIfcSectionedSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcSweptAreaSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCDIRECTRIXCURVESWEPTAREASOLID:
				return GenerateIfcDirectrixCurveSweptAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCEXTRUDEDAREASOLID:
				return GenerateIfcExtrudedAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCREVOLVEDAREASOLID:
				return GenerateIfcRevolvedAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcDirectrixCurveSweptAreaSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCFIXEDREFERENCESWEPTAREASOLID:
				return GenerateIfcFixedReferenceSweptAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSURFACECURVESWEPTAREASOLID:
				return GenerateIfcSurfaceCurveSweptAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcFixedReferenceSweptAreaSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCDIRECTRIXDERIVEDREFERENCESWEPTAREASOLID:
				return GenerateIfcDirectrixDerivedReferenceSweptAreaSolid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcFixedReferenceSweptAreaSolidImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcExtrudedAreaSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCEXTRUDEDAREASOLIDTAPERED:
				return GenerateIfcExtrudedAreaSolidTapered(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcExtrudedAreaSolidImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcRevolvedAreaSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCREVOLVEDAREASOLIDTAPERED:
				return GenerateIfcRevolvedAreaSolidTapered(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcRevolvedAreaSolidImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcSweptDiskSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCSWEPTDISKSOLIDPOLYGONAL:
				return GenerateIfcSweptDiskSolidPolygonal(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcSweptDiskSolidImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcManifoldSolidBrep(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCADVANCEDBREP:
				return GenerateIfcAdvancedBrep(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCFACETEDBREP:
				return GenerateIfcFacetedBrep(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcAdvancedBrep(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCADVANCEDBREPWITHVOIDS:
				return GenerateIfcAdvancedBrepWithVoids(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcAdvancedBrepImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcFacetedBrep(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCFACETEDBREPWITHVOIDS:
				return GenerateIfcFacetedBrepWithVoids(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcFacetedBrepImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcSectionedSolid(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCSECTIONEDSOLIDHORIZONTAL:
				return GenerateIfcSectionedSolidHorizontal(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCSWEPTSURFACE:
				return GenerateIfcSweptSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBOUNDEDSURFACE:
				return GenerateIfcBoundedSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCELEMENTARYSURFACE:
				return GenerateIfcElementarySurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSECTIONEDSURFACE:
				return GenerateIfcSectionedSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcSweptSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCSURFACEOFLINEAREXTRUSION:
				return GenerateIfcSurfaceOfLinearExtrusion(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSURFACEOFREVOLUTION:
				return GenerateIfcSurfaceOfRevolution(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcBoundedSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCURVEBOUNDEDPLANE:
				return GenerateIfcCurveBoundedPlane(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCURVEBOUNDEDSURFACE:
				return GenerateIfcCurveBoundedSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCRECTANGULARTRIMMEDSURFACE:
				return GenerateIfcRectangularTrimmedSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBSPLINESURFACE:
				return GenerateIfcBSplineSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcBSplineSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCBSPLINESURFACEWITHKNOTS:
				return GenerateIfcBSplineSurfaceWithKnots(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcBSplineSurfaceWithKnots(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCRATIONALBSPLINESURFACEWITHKNOTS:
				return GenerateIfcRationalBSplineSurfaceWithKnots(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcBSplineSurfaceWithKnotsImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcElementarySurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCPLANE:
				return GenerateIfcPlane(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSPHERICALSURFACE:
				return GenerateIfcSphericalSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCTOROIDALSURFACE:
				return GenerateIfcToroidalSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCYLINDRICALSURFACE:
				return GenerateIfcCylindricalSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
IfcGeometry GenerateIfcTessellatedItem(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCINDEXEDPOLYGONALFACE:
				return GenerateIfcIndexedPolygonalFace(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCTESSELLATEDFACESET:
				return GenerateIfcTessellatedFaceSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcIndexedPolygonalFace(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCINDEXEDPOLYGONALFACEWITHVOIDS:
				return GenerateIfcIndexedPolygonalFaceWithVoids(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcIndexedPolygonalFaceImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcTessellatedFaceSet(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCTRIANGULATEDFACESET:
				return GenerateIfcTriangulatedFaceSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOLYGONALFACESET:
				return GenerateIfcPolygonalFaceSet(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
IfcGeometry GenerateIfcTriangulatedFaceSet(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCTRIANGULATEDIRREGULARNETWORK:
				return GenerateIfcTriangulatedIrregularNetwork(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcTriangulatedFaceSetImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcTextLiteral(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCTEXTLITERALWITHEXTENT:
				return GenerateIfcTextLiteralWithExtent(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcTextLiteralImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcBooleanResult(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCBOOLEANCLIPPINGRESULT:
				return GenerateIfcBooleanClippingResult(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcBooleanResultImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::variant<std::vector<glm::dvec2>,std::vector<glm::dvec3>> GenerateIfcCartesianPointList(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCARTESIANPOINTLIST2D:
				return GenerateIfcCartesianPointList2D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCARTESIANPOINTLIST3D:
				return GenerateIfcCartesianPointList3D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::variant<std::vector<glm::dvec2>,std::vector<glm::dvec3>> result;
	return result;
	}
std::variant<glm::dmat2,glm::dmat4> GenerateIfcCartesianTransformationOperator(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCARTESIANTRANSFORMATIONOPERATOR2D:
				return GenerateIfcCartesianTransformationOperator2D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCARTESIANTRANSFORMATIONOPERATOR3D:
				return GenerateIfcCartesianTransformationOperator3D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::variant<glm::dmat2,glm::dmat4> result;
	return result;
	}
glm::dmat2 GenerateIfcCartesianTransformationOperator2D(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCARTESIANTRANSFORMATIONOPERATOR2DNONUNIFORM:
				return GenerateIfcCartesianTransformationOperator2DnonUniform(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcCartesianTransformationOperator2DImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
glm::dmat4 GenerateIfcCartesianTransformationOperator3D(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCARTESIANTRANSFORMATIONOPERATOR3DNONUNIFORM:
				return GenerateIfcCartesianTransformationOperator3DnonUniform(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcCartesianTransformationOperator3DImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
IfcGeometry GenerateIfcCsgPrimitive3D(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCRECTANGULARPYRAMID:
				return GenerateIfcRectangularPyramid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCRIGHTCIRCULARCONE:
				return GenerateIfcRightCircularCone(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCRIGHTCIRCULARCYLINDER:
				return GenerateIfcRightCircularCylinder(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSPHERE:
				return GenerateIfcSphere(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBLOCK:
				return GenerateIfcBlock(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	IfcGeometry result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCLINE:
				return GenerateIfcLine(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCOFFSETCURVE:
				return GenerateIfcOffsetCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPCURVE:
				return GenerateIfcPcurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOLYNOMIALCURVE:
				return GenerateIfcPolynomialCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSPIRAL:
				return GenerateIfcSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSURFACECURVE:
				return GenerateIfcSurfaceCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBOUNDEDCURVE:
				return GenerateIfcBoundedCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCONIC:
				return GenerateIfcConic(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcOffsetCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCOFFSETCURVE2D:
				return GenerateIfcOffsetCurve2D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCOFFSETCURVE3D:
				return GenerateIfcOffsetCurve3D(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCOFFSETCURVEBYDISTANCES:
				return GenerateIfcOffsetCurveByDistances(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcSpiral(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCTHIRDORDERPOLYNOMIALSPIRAL:
				return GenerateIfcThirdOrderPolynomialSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCLOTHOID:
				return GenerateIfcClothoid(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCOSINESPIRAL:
				return GenerateIfcCosineSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSECONDORDERPOLYNOMIALSPIRAL:
				return GenerateIfcSecondOrderPolynomialSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSEVENTHORDERPOLYNOMIALSPIRAL:
				return GenerateIfcSeventhOrderPolynomialSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSINESPIRAL:
				return GenerateIfcSineSpiral(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcSurfaceCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCINTERSECTIONCURVE:
				return GenerateIfcIntersectionCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSEAMCURVE:
				return GenerateIfcSeamCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcSurfaceCurveImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcBoundedCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCOMPOSITECURVE:
				return GenerateIfcCompositeCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCINDEXEDPOLYCURVE:
				return GenerateIfcIndexedPolyCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCPOLYLINE:
				return GenerateIfcPolyline(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCTRIMMEDCURVE:
				return GenerateIfcTrimmedCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCBSPLINECURVE:
				return GenerateIfcBSplineCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcCompositeCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCCOMPOSITECURVEONSURFACE:
				return GenerateIfcCompositeCurveOnSurface(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCGRADIENTCURVE:
				return GenerateIfcGradientCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCSEGMENTEDREFERENCECURVE:
				return GenerateIfcSegmentedReferenceCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcCompositeCurveImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcCompositeCurveOnSurface(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCBOUNDARYCURVE:
				return GenerateIfcBoundaryCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcCompositeCurveOnSurfaceImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcBoundaryCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCOUTERBOUNDARYCURVE:
				return GenerateIfcOuterBoundaryCurve(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcBoundaryCurveImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcBSplineCurve(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCBSPLINECURVEWITHKNOTS:
				return GenerateIfcBSplineCurveWithKnots(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
std::vector<glm::dvec3> GenerateIfcBSplineCurveWithKnots(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCRATIONALBSPLINECURVEWITHKNOTS:
				return GenerateIfcRationalBSplineCurveWithKnots(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			default:
				return GenerateIfcBSplineCurveWithKnotsImpl(expressID,lineType,loader,cache,settings,cacheOff);
		}
	}
std::vector<glm::dvec3> GenerateIfcConic(const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, bool cacheOff) {
		switch(lineType) {
			 case webifc::schema::IFCELLIPSE:
				return GenerateIfcEllipse(expressID,lineType,loader,cache,settings,cacheOff);
				break;
			 case webifc::schema::IFCCIRCLE:
				return GenerateIfcCircle(expressID,lineType,loader,cache,settings,cacheOff);
				break;
		}
	std::vector<glm::dvec3> result;
	return result;
	}
}
