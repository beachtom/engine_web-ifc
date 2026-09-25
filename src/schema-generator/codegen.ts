let returnTypeMap = new Map<String,Array<String>>()
returnTypeMap["IfcGeometry"] = ["IfcIndexedPolygonalFaceWithVoids","IfcIndexedPolygonalFace","IfcFacetedBrepWithVoids","IfcFacetedBrep","IfcAdvancedBrep","IfcAdvancedBrepWithVoids","IfcPolygonalBoundedHalfSpace","IfcBoxedHalfSpace","IfcSectionedSolidHorizontal","IfcSurfaceCurveSweptAreaSolid","IfcShellBasedSurfaceModel","IfcConnectedFaceSet","IfcGeometricSet","IfcGeometricCurveSet","IfcTriangulatedFaceSet","IfcTriangulatedIrregularNetwork","IfcPolygonalFaceSet","IfcTextLiteral","IfcTextLiteralWithExtent","IfcBooleanClippingResult","IfcDirectrixDerivedReferenceSweptAreaSolid","IfcFixedReferenceSweptAreaSolid","IfcSweptDiskSolid","IfcSweptDiskSolidPolygonal","IfcCsgSolid","IfcRevolvedAreaSolidTapered","IfcRevolvedAreaSolid","IfcExtrudedAreaSolidTapered","IfcExtrudedAreaSolid","IfcBooleanResult","IfcRectangularPyramid","IfcRightCircularCone","IfcRightCircularCylinder","IfcOpenShell","IfcClosedShell","IfcMappedItem","IfcSphere","IfcBlock","IfcHalfSpaceSolid"]
returnTypeMap["std::vector<glm::dvec3>"]= ["IfcPlanarExtent","IfcFaceSurface","IfcFaceBasedSurfaceModel","IfcSurfaceOfRevolution","IfcSurfaceOfLinearExtrusion","IfcAdvancedFace","IfcCurveBoundedPlane","IfcCurveBoundedSurface","IfcRectangularTrimmedSurface","IfcBSplineSurfaceWithKnots","IfcRationalBSplineSurfaceWithKnots","IfcPlane","IfcSphericalSurface","IfcToroidalSurface","IfcCylindricalSurface","IfcSectionedSurface","IfcBoundingBox","IfcCartesianPointList3D","IfcFaceOuterBound","IfcFaceBound","IfcPlanarBox","IfcSectionedSpine","IfcCompositeCurveSegment","IfcReparametrisedCompositeCurveSegment","IfcCurveSegment","IfcPolynomialCurve","IfcThirdOrderPolynomialSpiral","IfcClothoid","IfcCosineSpiral","IfcSecondOrderPolynomialSpiral","IfcSeventhOrderPolynomialSpiral","IfcSineSpiral","IfcBSplineCurveWithKnots","IfcRationalBSplineCurveWithKnots","IfcEdgeCurve","IfcEdge","IfcFace","IfcSubedge","IfcOrientedEdge","IfcLoop","IfcPolyLoop","IfcVertexLoop","IfcEdgeLoop","IfcPath","IfcCircle","IfcEllipse","IfcTrimmedCurve","IfcPolyline","IfcIndexedPolyCurve","IfcSegmentedReferenceCurve","IfcGradientCurve","IfcOuterBoundaryCurve","IfcBoundaryCurve","IfcCompositeCurveOnSurface","IfcCompositeCurve","IfcSeamCurve","IfcIntersectionCurve","IfcSurfaceCurve","IfcPcurve","IfcOffsetCurveByDistances","IfcOffsetCurve3D","IfcOffsetCurve2D","IfcLine"];
returnTypeMap["glm::dvec3"]= ["IfcDirection","IfcVertexPoint","IfcVertex","IfcPointOnCurve","IfcPointOnSurface","IfcCartesianPoint","IfcPointByDistanceExpression"];
returnTypeMap["glm::dvec4"]=["IfcLightSourceSpot","IfcLightSourcePositional","IfcLightSourceGoniometric","IfcLightSourceAmbient","IfcLightSourceDirectional","IfcVector","IfcFillAreaStyleTiles","IfcFillAreaStyleHatching","IfcStyledItem","IfcAnnotationFillArea"]
returnTypeMap["glm::dmat2"]=["IfcCartesianTransformationOperator2D","IfcCartesianTransformationOperator2DnonUniform"]
returnTypeMap["glm::dmat4"]=["IfcAxis1Placement","IfcAxis2Placement2D","IfcAxis2Placement3D","IfcAxis2PlacementLinear","IfcCartesianTransformationOperator3D","IfcCartesianTransformationOperator3DnonUniform"]
returnTypeMap["std::vector<glm::dvec2>"]=["IfcCartesianPointList2D"]

function findElementByParent(entities : Array<Entity>,parentName :string) {
	let results = new Array<Entity>();
	for (let entity of entities) {
		if (entity.parent == parentName) {
			results.push(entity);
			var res = findElementByParent(entities,entity.name);
			results.push(...res)
		}
	}
	return results;
}

function getReturnTypeRaw(element:string) {
	for (let retType in returnTypeMap)
	{
		for (let type of returnTypeMap[retType]) {
			if (type == element) return retType
		}
	}
	return undefined
}

function getReturnTypeRouting(element: string,entities : Array<Entity>) {
	let returnType = getReturnTypeRaw(element)
	if (returnType != undefined) return	returnType;
	let children = getImmediateChildren(entities,element)
	let returnsTypes = new Set()
	for (let child of children) {
		var result = getReturnTypeRouting(child,entities);
		if (result instanceof Set) returnsTypes.add(...result)
		else returnsTypes.add(result)
	}
	return returnsTypes
}

function getImmediateChildren(entities : Array<Entity>,parentName :string) {
	let results = new Array<Entity>();
	for (let entity of entities) {
		if (entity.parent == parentName) results.push(entity.name);
	}
	return results;
}

function getReturnType(name:string, entities:Array<Entity>) {
	let returnTypeList = getReturnTypeRouting(name,entities)
	if (returnTypeList instanceof Set) {
		if (returnTypeList.size > 1) {
			return "std::variant<"+[...returnTypeList].join(',')+">"
		} else if (returnTypeList.size == 1){
			return returnTypeList.values().next().value
		} else {
			console.log(element.name+"ERROR DECIDING RETURN TYPE")
		}
	} else return returnTypeList
}


import {Entity} from "./gen_functional_types_interfaces";
import {parseElements, walkParents,sortEntities, findSubClasses} from "./gen_functional_types_helpers"
import schemaAliases from "./schema_aliases";
const fs = require("fs");
const files: string[] = ["", ...fs.readdirSync("./").filter((name: string) => name.endsWith(".exp")).sort()];
const file = files[files.length-1];
console.log("Generating Geometry Code Based on:"+file);
let schemaData = fs.readFileSync("./"+file).toString();
let parsed = parseElements(schemaData);
let entities: Array<Entity> = sortEntities(parsed.entities);
entities.forEach((e) => {
	walkParents(e,entities);
});

let representationElements = findElementByParent(entities,"IfcRepresentationItem")

let header: Array<string> = [];
let routing: Array<string> = [];
header.push(`#include <variant>`)
header.push(`#include "../../parsing/IfcLoader.h"`)
header.push(`#include "../../cache/IfcCache.h"`)
header.push(`#include "IfcGeometry.h"`)
header.push(`#include "GeometryGeneratorSettings.h"`)
routing.push(`#include "generators.h"`)
header.push("namespace webifc::geometry::generators {")

header.push(" template <typename TargetVariant, typename SourceVariant> TargetVariant variant_cast(SourceVariant&& source) { return std::visit([](auto&& arg) -> TargetVariant { return std::forward<decltype(arg)>(arg); }, std::forward<SourceVariant>(source));}");

routing.push("namespace webifc::geometry::generators {")
fs.mkdir("../cpp/web-ifc/geometry/generators/implementation/", { recursive: true }, () => {});

let parameters = "const uint32_t expressID, const uint32_t lineType, webifc::parsing::IfcLoader &loader, webifc::cache::IfcCache &cache, GeometryGeneratorSettings &settings, const bool cacheOff"
let parametersNames = "expressID,lineType,loader,cache,settings,cacheOff"

for (let element of representationElements) {
	let children = getImmediateChildren(entities,element.name)
	if (children.length > 0) {
		let returnType = getReturnType(element.name,entities);
		
 		header.push(`${returnType} Generate${element.name}(${parameters}=false);`)
		routing.push(`${returnType} Generate${element.name}(${parameters}) {`)
		routing.push(`\t\tswitch(lineType) {`)
		for (let child of children) {
			routing.push(`\t\t\t case webifc::schema::${child.toUpperCase()}:`)
			let innerReturnType = getReturnType(child,entities)
			if (innerReturnType != returnType && innerReturnType.includes("std::variant") && returnType.includes("std::variant")) {
				routing.push(`\t\t\t\treturn variant_cast<${returnType}>(Generate${child}(${parametersNames}));`)
			}
			else routing.push(`\t\t\t\treturn Generate${child}(${parametersNames});`)
			routing.push(`\t\t\t\tbreak;`)
		}
		if (!element.abstract) {
			routing.push(`\t\t\tdefault:`)
			routing.push(`\t\t\t\treturn Generate${element.name}Impl(${parametersNames});`)
		}
		routing.push(`\t\t}`)
		if (element.abstract) {
			routing.push(`\t${returnType} result;`)
			routing.push(`\treturn result;`)
		}
		routing.push(`\t}`)
	}
	if (!element.abstract) {
		let returnType = getReturnTypeRaw(element.name)
		if (returnType == undefined) {
			console.log("ERROR: Unmapped Type:"+element);
			process.exit()
		}
		if (children.length > 0) header.push(`${returnType} Generate${element.name}Impl(${parameters});`)
		else header.push(`${returnType} Generate${element.name}(${parameters}=false);`)
		let implementation: Array<string> = [];
		implementation.push("#include <spdlog/spdlog.h>")
		implementation.push(`#include "../generators.h"`)
		implementation.push("namespace webifc::geometry::generators {")
		if (children.length > 0) implementation.push(`\t${getReturnTypeRaw(element.name)} Generate${element.name}Impl(${parameters.replace(" lineType","")}) {`)
		else implementation.push(`\t${getReturnTypeRaw(element.name)} Generate${element.name}(${parameters.replace(" lineType","")}) {`)
		implementation.push(`\t\tif (!cacheOff) {`)
		implementation.push(`\t\t\tauto cacheHit = cache.Get<${getReturnTypeRaw(element.name)}>(expressID);`)
		implementation.push(`\t\t\tif (cacheHit.has_value()) return cacheHit->get();`)
		implementation.push(`\t\t}`)
		implementation.push(`\t\tspdlog::debug("[Generate${element.name}Impl({})]", expressID);`)
		implementation.push(`\t\t${getReturnTypeRaw(element.name)} result;`)
		implementation.push(`\t\t`)
		implementation.push(`\t\tif (!cacheOff) cache.Cache(expressID,result);`)
		implementation.push(`\t\treturn result;`)
		implementation.push(`\t}`)
		implementation.push("}");
		implementation.push("");
		fs.writeFileSync("../cpp/web-ifc/geometry/generators/implementation/"+element.name+".cpp", implementation.join("\n")); 
	}
}

header.push("}");
routing.push("}");
routing.push("");
header.push("");
fs.writeFileSync("../cpp/web-ifc/geometry/generators/generators.h", header.join("\n")); 
fs.writeFileSync("../cpp/web-ifc/geometry/generators/generators.cpp", routing.join("\n")); 