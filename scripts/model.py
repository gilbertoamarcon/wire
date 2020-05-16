#!/usr/bin/env python

import argparse
import yaml
from xml.dom import minidom
from svg.path import parse_path
from svg.path import Line

def main():

	# Parsing user input
	parser = argparse.ArgumentParser()
	parser.add_argument(
			'-i','--input',
			nargs='?',
			type=str,
			required=True,
			help='Input file name.'
		)
	parser.add_argument(
			'-o','--output',
			nargs='?',
			type=str,
			required=True,
			help='Output file name.'
		)
	args = parser.parse_args()

	doc = minidom.parse(args.input)

	shape = []
	for p in doc.getElementsByTagName('path'):
		path = parse_path(p.getAttribute('d'))
		for cmd in path:
			if type(cmd) == Line:
				line = {
					'start':{
						'x': cmd.start.real,
						'y': cmd.start.imag,
					},
					'end': {
						'x': cmd.end.real,
						'y': cmd.end.imag,
					}
				}
				shape.append(line)
	with open(args.output,'w') as f:
		f.write(yaml.dump(shape))


if __name__ == "__main__":
	main()





