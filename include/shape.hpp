#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "geom.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>

class Shape {

private:
	std::list<Geom::Line> shape;
	YAML::Node loadShapeFile(std::string filename);
	Geom::Pos loadPos(YAML::Node node);

public:
	Shape() {};
	void load(std::string filename);
	const std::list<Geom::Line> getShape() const { return shape; };

};

#endif
