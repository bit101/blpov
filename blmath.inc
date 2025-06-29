#declare tau = pi * 2;

#macro Lerp(T, Min, Max)
  Min + (Max-Min)*T
#end

#macro Normal(Val, Min, Max)
  #local N = 0.5;
  #if (Min != Max)
    #local N = (Val - Min) / (Max - Min);
  #end
  N
#end

#macro Map(Val, SrcMin, SrcMax, DstMin, DstMax)
  #local N = Normal(Val, SrcMin, SrcMax);
  Lerp(N, DstMin, DstMax)
#end

#macro LoopSin(T, Min, Max)
  Map(cos(T * tau), 1, -1, Min, Max)
#end
