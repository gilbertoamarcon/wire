#include "shape.hpp"




void Shape::load(std::string filename){
	YAML::Node data = loadShapeFile(filename);
	for(const auto & yamlLine :  data)
		if(yamlLine["start"] && yamlLine["end"]){
			Geom::Pos start = loadPos(yamlLine["start"]);
			Geom::Pos end = loadPos(yamlLine["end"]);
			Geom::Line line(start, end);
			shape.push_front(line);
		}
};

YAML::Node Shape::loadShapeFile(std::string filename){
	try{
		return YAML::LoadFile(filename);
	}
	catch(std::exception &e){
		std::cout << "Error loading the shape file " << filename << std::endl;
		return YAML::Node();
	}
};

Geom::Pos Shape::loadPos(YAML::Node node){
	if(node["x"] && node["y"])
		return Geom::Pos(
			node["x"].as<float>(),
			node["y"].as<float>()
		);
	else
		return Geom::Pos(0,0);
};
