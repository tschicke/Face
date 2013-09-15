/*
 * Face.h
 *
 *  Created on: Sep 14, 2013
 *      Author: Tyler
 */

#ifndef FACE_H_
#define FACE_H_

class Face {
public:
	Face();
	virtual ~Face();

	void createFace(const char * file1, const char * file2);
	void resetFace();

	void draw();


	//Make Private
	int npindices;  // number of polygon indices
	int *indexlist;  // integer index list of size npindices*4

	int npolylinenodes;  // number of nodes in the poly line
	float *polyline;  // xyz nodes in the poly line

	int npolygons;  // total number of polygons
	POLYGON **polygon;  // pointer to the polygon list

	int neyelidtags;  // number of eyelid tags
	TAG **eyelidtag;  // pointer to the eyelid tags
	float eyelidang;  // rotation of the eyelids

	int njawtags;  // number of jaw tags
	TAG **jawtag;  // pointer to the eyelid tags
	float jawang;  // rotation of the jaw

	int nmuscles;  // number of muscles in the face
	MUSCLE **muscle;  // pointer to the muscle list

	int nexpressions;  // number of expressions in the
	EXPRESSION **expression;  // point to an expression vector

	int rendermode;  // wireframe, flat, smooth or textured
	int current_muscle;  // the current muscle to be activated
	int current_exp;  // the current facial expression

	int TextureFunction;  // The texture function DECAL or MODULATE
private:
	void constructFace();
};

#endif /* FACE_H_ */
