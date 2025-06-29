#include "rand.inc"
#include "blmath.inc"

////////////////////
// Vector Utils
////////////////////

// Rotates a vector around each axis by so many degrees.
#macro VectorRotate(V, Rx, Ry, Rz)
  vrotate(V, <Rx, Ry, Rz>)
#end

// Rotates a vector around the x axis by so many degrees.
#macro VectorRotateX(V, Angle)
  vrotate(V, <Angle, 0, 0>)
#end

// Rotates a vector around the x axis by so many degrees.
#macro VectorRotateY(V, Angle)
  vrotate(V, <0, Angle, 0>)
#end

// Rotates a vector around the x axis by so many degrees.
#macro VectorRotateZ(V, Angle)
  vrotate(V, <0, 0, Angle>)
#end


////////////////////
// Misc Shapes
////////////////////

// Creates a box centered on X, Y, Z with the specified dimensions.
#macro Box(X, Y, Z, W, H, D)
  box {
    <X - W/2, Y - H/2, Z - D/2>
    <X + W/2, Y + H/2, Z + D/2>
  }
#end

