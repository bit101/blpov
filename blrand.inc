#include "rand.inc"
#include "blmath.inc"
#include "blgeom.inc"

////////////////////
// Seeding
////////////////////

// initial default stream.
#declare BLStream = seed(0);

// set seed
#macro Seed(NewSeed)
  #declare BLStream = seed(NewSeed);
#end

// Creates a random number generator with the seed based on the current time.
#macro RandomSeed()
  #declare BLStream = seed(now * 24 * 60 * 60);
#end

////////////////////
// Numbers
////////////////////

// Random float from 0 to 1.
#macro RandomFloat()
  rand(BLStream)
#end

// Random float in given range.
#macro RandomFloatRange(Min, Max)
  RRand(Min, Max, BLStream)
#end

#macro RandomIntRange(Min, Max)
  floor(RandomFloatRange(Min, Max))
#end

////////////////////
// Angles
////////////////////

#macro RandomRadian()
  RandomFloatRange(0, tau)
#end

#macro RandomDegree()
  RandomFloatRange(0, 360)
#end

////////////////////
// Colors
////////////////////

// Creates a random RGB color.
#macro RandomRGB()
  rgb <rand(BLStream), rand(BLStream), rand(BLStream)>
#end

// Creates a random Gray color.
#macro RandomGray()
  rgb rand(BLStream)
#end

// Creates a random Gray color within a min/max range.
#macro RandomGrayRange(Min, Max)
  rgb RandomFloatRange(Min, Max)
#end

////////////////////
// Bools
////////////////////

// Random true / false (coin flip).
#macro RandomBool()
  // #local B = false;
  // #if (rand(BLStream) < 0.5)
  //   #local B = true;
  // #end
  // B
  rand(BLStream) < 0.5
#end

// Weighted coin flip.
#macro RandomWeightedBool(W)
  // #local B = false;
  // #if (rand(BLStream) < W)
  //   #local B = true;
  // #end
  // B
  rand(BLStream) < W
#end


////////////////////
// Random Points
////////////////////

// Creates a random point in a box.
#macro RandomPointInBox(Pa, Pb)
  VRand_In_Box(Pa, Pb, BLStream)
#end

// Creates a random point on the surface of a sphere.
#macro RandomPointOnSphere(R)
  VRand_On_Sphere(BLStream) * R
#end

// Creates a random point within a sphere.
#macro RandomPointInSphere(R)
  VRand_In_Sphere(BLStream) * R
#end

// Creates a random point on the surface of a torus.
#macro RandomPointOnTorus(R1, R2, Arc)
  #local T = RandomRadian();
  #local V = <cos(T) * R2 + R1, sin(T) * R2, 0>;
  VectorRotateY(V, RandomFloat() * Arc)
#end

// Creates a random point inside a torus.
#macro RandomPointInTorus(R1, R2, Arc)
  #local T = RandomRadian();
  #local R2 = R2 * sqrt(RandomFloat());
  #local V = <cos(T) * R2 + R1, sin(T) * R2, 0>;
  VectorRotateY(V, Float() * Arc)
#end

// Creates a random point in a circle (at origin, on X/Z plane).
#macro RandomPointInCircle(Radius)
  #local A = RandomRadian();
  <cos(A) * Radius, 0, sin(A) * Radius>
#end

// Creates a random point in a rectangle (at origin, on X/Z plane).
#macro RandomPointInRect(W, D)
  <RandomFloatRange(-W/2, W/2), 0, RandomFloatRange(-D/2, D/2)>
#end

// Creates a random point inside a cylinder.
#macro RandomPointInCylinder(Height, Radius)
  #local R = sqrt(RandomFloat()) * Radius;
  #local A = RandomRadian();
  <cos(A) * R, RandomFloatRange(-Height/2, Height/2), sin(A) * R>
#end

// Creates a random point on the surface a cylinder.
#macro RandomPointOnCylinder(Height, Radius, Caps)
  #local A = RandomRadian();
  #local CylArea = Radius * tau * Height;
  #local CapArea = pi * Radius * Radius;
  #local Area = CylArea + CapArea * 2;

  #local N = RandomFloat() * Area;
  #if (!Caps | N < CylArea)
    #local Point = <cos(A) * Radius, RandomFloatRange(-Height/2, Height/2), sin(A) * Radius>;
  #else
    #local R = sqrt(RandomFloat()) * Radius;
    #local Point = RandomPointInCircle(R)
    #if (N < CylArea + CapArea)
      #local Point = Point - <0, Height/2, 0>;
    #else
      #local Point = Point + <0, Height/2, 0>;
    #end
  #end
  Point
#end

// Creates a random point between the two given points.
#macro RandomPointOnLine(Pa, Pb)
  VectorLerp(RandomFloat(), Pa, Pb)
#end


////////////////////
// Randomize other things
////////////////////

// Randomizes a vector on each axis.
#macro VectorRandomize(V, X, Y, Z)
  <V.x + RandomFloatRange(-X/2, X/2), V.y + RandomFloatRange(-Y/2, Y/2), V.z + RandomFloatRange(-Z/2, Z/2)>
#end

// Creates a random bidirectional translation on each axis.
#macro RandomTranslate(X, Y, Z)
  translate <RandomFloatRange(-X/2, X/2), RandomFloatRange(-Y/2, Y/2), RandomFloatRange(-Z/2, Z/2)>
#end

// Creates a random bidirectional rotation on each axis.
#macro RandomRotate(X, Y, Z)
  rotate <RandomFloatRange(-X/2, X/2), RandomFloatRange(-Y/2, Y/2), RandomFloatRange(-Z/2, Z/2)>
#end

// Creates a random scale on each axis from 1 to the given value.
#macro RandomScale(X, Y, Z)
  scale <RandomFloatRange(1, X), RandomFloatRange(1, Y), RandomFloatRange(1, Z)>
#end

// Creates a random scale the same on all axis from 1 to the given value.
#macro RandomUniScale(S)
  scale RandomFloatRange(1, S)
#end
