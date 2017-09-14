//
//  Object.h
//  sep14
//
//  Created by chaearn on 9/14/17.
//
//

#ifndef Object_h
#define Object_h

#include "ofMain.h"

class Object {
public:
    
    // methods, equivalent to specific functions of your class objects
    void setup(float _x, float _y, int _dim);	// setup method, use this to setup your object's initial state
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    
    // variables
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    ofColor color;  // color using ofColor type
    
    Object();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
private: // place private functions or variables declarations here
    
};


#endif /* Object_h */
