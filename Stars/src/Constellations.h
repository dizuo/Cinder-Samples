/*
 Copyright (c) 2010-2012, Paul Houx - All rights reserved.
 This code is intended for use with the Cinder C++ library: http://libcinder.org

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "cinder/DataSource.h"
#include "cinder/DataTarget.h"
#include "cinder/Utilities.h"

#include "cinder/gl/Vbo.h"

class Constellations
{
public:
	Constellations(void);
	~Constellations(void);

	void setup() {};
	void update() {};
	void draw();

	void	clear();

	void	setCameraDistance( float distance );
	void	setLineWidth( float width ) { mLineWidth = width; }

	//! load a comma separated file containing the HYG star database
	void	load( ci::DataSourceRef source );

	//! reads a binary label data file
	void	read( ci::DataSourceRef source );
	//! writes a binary label data file
	void	write( ci::DataTargetRef target );
private:
	void						createMesh();

	ci::Vec3d					getStarCoordinate( double ra, double dec, double distance );
	std::vector< ci::Vec3d >	getStarCoordinates( ci::DataSourceRef source );
private:
	ci::gl::VboMesh				mMesh;

	std::vector< ci::Vec3f >	mVertices;
	std::vector< uint32_t >		mIndices;

	float						mAttenuation;
	float						mLineWidth;
};

