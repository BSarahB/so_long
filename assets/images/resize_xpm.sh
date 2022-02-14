#!/bin/bash

IMAGES="$(ls *.xpm)"
#SIZES="16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32"

#for size in ${SIZES}
for size in {1..32}
do
    DIR="${size}"
	mkdir -p "xpm/${DIR}"
	for image in ${IMAGES}
    do
		convert ${image} -resize ${size} "xpm/${DIR}/${image}"
	done
done

