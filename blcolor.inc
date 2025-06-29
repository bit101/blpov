#include "colors.inc"

#macro HSV(H, S, V)
  rgb CHSV2RGB(<H, S, V>)
#end

// Creates an 
#macro HSL(H, S, L)
  rgb CHSL2RGB(<H, S, L>)
#end
