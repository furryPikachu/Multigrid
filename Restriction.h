#ifndef RESTRICTION_H
#define RESTRICTION_H

#include "Real.h"
#include <vector>
class Restriction
{
public:
  virtual std::vector<Real> restriction
  (const std::vector<Real> &x ) = 0 ;
protected:
  Restriction(){}
  
};

class Injection : public Restriction
{
 std::vector<Real> restriction (const std::vector<Real> &x )
  {
    std::vector<Real> result;
    int n = x.size();
    for(int i=0; i< (n-1)/2; i++)
      result.push_back(x[2*i+1]);
    return result;
  }
};

class FullWeighting : public Restriction
{
  std::vector<Real> restriction ( const std::vector<Real> &x )
  {
    std::vector<Real> result;
    int n = x.size();
    for(int i=0; i< (n-1)/2; i++)
      result.push_back(0.25*(2*x[2*i+1]+x[2*i+2]+x[2*i]));
    return result;
  }
};

#endif
