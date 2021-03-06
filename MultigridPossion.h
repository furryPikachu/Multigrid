#ifndef MUTIGRIDPOISSON_H
#define MUTIGRIDPOISSON_H

typedef double Real;
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <initializer_list>
#include <numeric>
#include <cmath>
#include <cassert> 
#include <lapacke.h>
#include <cblas.h>
#include "Real.h"
#include "func.h"
#include "Restriction.h"
#include "Interpolation.h"
#include "MGLevelOp.h"


#define PI 3.14159265

 // std::vector<Real> Relax(int n,  const std::vector<Real> &_guess,
 //                               int nu_1, Real lamda ) ;
///
/*
Implement the multigrid solver for the one-dimensional
Possion equation with the Dirichlet boundary condition
 */

///User can define :
/*
boundary condition
restriction operation: full-weighting and nonhomogeneous
interpolation operation: linear and quadratic
cycles: V-cycle and full multigrid cycle
stopping criteria:
the number of maximum iterations and the relative accuracy epsilon
 */
//template <int dim>
class MultigridPossion
{
  std::vector<Real> boundary={0,0};//boundary operation
  Real eps;           //stopping criteria
  int maxIter ;
   
  enum interpolation {linear=1, quadratic};
  enum cycles {V, full_multigrid};
   enum restriction {fullWeighting, injection};
  std::vector<Real> guess;
  //std::vector<Real> solution;
  int gridsize;
  //  MGLevelOp op;
public:
  std::vector<Real> funcValue;
  
 
public:
  // generat the functionvalue:
  //the value is -\Delta u= f and modified by the boundary condition
   void generatFuncValue(Func &f){
     int n=gridsize;
     double h=1.0/n;
    for (int i=1; i<n; i++)
      (funcValue).push_back(f(i*(1.0/n)));
  }

  void setArguments(int cycles, int interpolation,
                    int restriction){
  }
  
public:
  // static CppUnit::TestSuite *suite();

public:
  
  int getGridsize(){
    return gridsize;
  }
  
  std::vector<Real> getFuncValue(){
    return funcValue;
  }
  std::vector<Real> getBoundary(){
    return boundary;
  }
  Real getEps(){
    return eps; 
    }
  int getMaxIter(){
    return maxIter;
  }
  
// public:
//   std::vector<Real> Relax(int n,
//                           std::vector<Real> &_fvalue,
//                           std::vector<Real> &guess,
//                           int nu_1=1,
//                           Real lamda = 2.0/3.0) ;
public:
  std::vector<Real> Vcycle( int n,
                            std::vector<Real> &_fvalue, Restriction &rest,
                            Interpolation & inter,
                            int nu_1, int nu_2,
                            std::vector<Real> &init);
  
  std::vector<Real> Full( int n,
                          std::vector<Real> &_fvalue, Restriction &rest,
                            Interpolation & inter,
                          int nu_1, int nu_2, int nu_0=5);
                       
  
public:
  ///
  /**
 constructor
  */
  MultigridPossion() : boundary({0,0}), eps( 0.00000001), maxIter(1000),
                       gridsize(2){}
  MultigridPossion(Real u1, Real u2) : boundary({u1,u2}), eps( 0.00000001), maxIter(1000){}
  MultigridPossion(Real u1, Real u2, int x, int n, Real _eps) : boundary({u1,u2}), maxIter(x), gridsize(n), eps(_eps){ }
  MultigridPossion(Real u1, Real u2, Real x, int y) : boundary({u1,u2}), eps(x), maxIter(y){}
    
};




//#include "MultigridPossion.cpp"
  

#endif
