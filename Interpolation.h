#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "Real.h"
#include <vector>
class Interpolation
{
public:
  virtual std::vector<Real> interpolation
  (const std::vector<Real> x )  =0;
protected:
  Interpolation(){}
  
};

class Linear : public Interpolation
{
 std::vector<Real> interpolation ( std::vector<Real> x )
  {
    std::vector<Real> that = x;
    that.push_back(0);
    std::vector<Real> result;
    int n = x.size();
    result.push_back( (x[0])/2 );
    for(int i=0; i< n-1; i++)
      {
      result.push_back(x[i]);
      result.push_back( (x[i]+x[i+1])/2 );
      }
    result.push_back( (x[n-1]) );
      result.push_back( (x[n-1])/2 );
    return result;
  }
};

class Quadratic : public Interpolation
{
  std::vector<Real> interpolation (std::vector<Real> x )
  {
    std::vector<Real> that=x;
    that.push_back(0);
    std::vector<Real> result;
    int n = x.size();
    result.push_back(that[0]*0.75-that[1]*0.125);
     result.push_back(that[0]);
     result.push_back(that[0]*0.75+that[1]*0.375);
    
    for(int i=1; i< n-2 ; i=i+2)
      {
        result.push_back(x[i]);            
      result.push_back( that[i]*0.375+that[i+1]*0.75-that[i+2]*0.125 );
        result.push_back(x[i+1]);
        result.push_back( -that[i]*0.125+that[i+1]*0.75+that[i+2]*0.375 );
      }

       result.push_back(x[n-2]);            
      result.push_back( that[n-1]*0.75+that[n-2]*0.375 );
      
       result.push_back(x[n-1]);            
      result.push_back( that[n-1]*0.75-that[n-2]*0.125 );
    return result;
  }
};

#endif
