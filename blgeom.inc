// Should not include blrand as blrand includes blgeom.
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

// Creates a new vector interpolated betwee the given two.
#macro VectorLerp(T, Va, Vb)
  #local X = Lerp(T, Va.x, Vb.x);
  #local Y = Lerp(T, Va.y, Vb.y);
  #local Z = Lerp(T, Va.z, Vb.z);
  <X, Y, Z>
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

#macro SphereCage(Long, Lat, R1, R2)
  #local Long = Long + 1;
  union {
    #if (Long > 0)
      #for (i, 0, Long)
        #declare N = i / Long * pi;
        #declare A = N * pi;
        torus {
          sin(N)*R1, R2
          translate cos(N)*R1 * y
        }
      #end
    #end
    #if (Lat > 0)
      #for (i, 0, Lat)
        difference {
          torus {
            R1, R2
          }
          box {
            <-R1*2, -R2*2, -R1*2>
            <0, R2*2, R1*2>
          }
          rotate <90, i/Lat * 360, 0>
        }
      #end
    #end
  }
#end
