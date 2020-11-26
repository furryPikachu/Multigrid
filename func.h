// #include<iostream>
// #include <cmath>
#ifndef FUNC_H
#define FUNC_H

class Func
{
 public:
  virtual double operator() (const double x) const=0;
 };

class func0 : public Func
{
  double operator() (const double x) const{
    return (0.0 );
  }
};

class func1 : public Func
{

  double operator() (const double x) const{
    return ( -(cos(x)*cos(x)-sin(x))*exp(sin(x)) );
  }
};

class func2 : public Func
{
  double operator() (const double x) const{
    return ( exp(sin(x)) );
  }
};


#endif
