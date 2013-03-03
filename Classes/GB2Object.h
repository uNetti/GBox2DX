/*
 MIT License
 
 Copyright (c) 2010 Andreas Loew / www.code-and-web.de
 Copyright (c) 2012 Chris Hannon / channon.us
 Copyright (c) 2013 Lars Kinnunen / unetti.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
#ifndef __GB2OBJECT_H__
#define __GB2OBJECT_H__

#include "GB2Config.h"

NS_GB_BEGIN

/**
* An abstract class to be inherited by any class needing the nameForObject method for collision registry
*/
class GB2Object
{
	/**
	 * A pure virtual method to be overridden by inheriting classes
	 * @return the name for the object to be used in collision handling determination
	 */
	virtual const char *nameForObject() const = 0;
};

/**
* A macro to override the nameForObject method in order for a class to be included in collision handling
*/
#define COLLISION_OBJECT(A) const char *nameForObject() const {return #A;}

NS_GB_END

#endif // __GB2OBJECT_H__