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
#ifndef __GB2WORLDCONTACTLISTENER_H__
#define __GB2WORLDCONTACTLISTENER_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GB2Node.h"

/**
 * GB2WorldContactListener
 *
 * This class is an implementation of the b2ContactListener which
 * handles collisions between objects
 *
 * The implementation asumes that the user data in the b2Body objects
 * is an GB2Object* 
 *
 * It automatically calls selectors for the collision detection.
 * E.g. if you have 2 objects colliding, one with a class named
 * Stone and one with a class named Floor it will call the following
 * selectors
 *   aFloor::beginContactWithStone(GB2Node* otherObject, GB2Collision *c)
 *   aStone::beginContactWithFloor(GB2Node* otherObject, GB2Collision *c)
 * for each point of the contact.
 *
 * For each lost contact point
 *   aFloor::endContactWithStone(GB2Node* otherObject, GB2Collision *c)
 *   aStone::endContactWithFloor(GB2Node* otherObject, GB2Collision *c)
 * will be called.
 *
 * During the endContactWith* and beginContactWith* selector calls
 * you must not destroy the object or change the object's physical
 * shape!
 *
 * The functions are called for each contact point. To detect if
 * some objects have contact you need to count the number of 
 * begin and end calls or track the object's state change.
 *
 * During the presolve phase it is possible to disable collisions
 * e.g. if a player picksup an object you usually don't want him to
 * bump into the object but just pass through it.
 *
 * In this case 
 *  aFloor::preContactWithStone(GB2Node* otherObject, GB2Collision *c)
 *  aStone::preContactWithFloor(GB2Node* otherObject, GB2Collision *c)
 * are called
 *
 * From within one of these selectors you can call
 *   [contact setEnabled:NO];
 * to disable the collition for this contact.
 *
 */

class GB2WorldContactListener : public b2ContactListener
{
public:
    GB2WorldContactListener() ;
	~GB2WorldContactListener() ;    
	virtual void BeginContact(b2Contact* contact); 
	virtual void EndContact(b2Contact* contact);
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);    
	void notifyObjects(b2Contact *contact, std::string contactType);
protected:
};

#endif  // __GB2ENGINE_H__