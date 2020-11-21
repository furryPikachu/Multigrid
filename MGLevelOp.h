#ifndef MGLEVELOP
#define MGLEVELOP

class MGLevelOp
{
public:
  virtual std::vector<Real> Smooth(  std::vector<Real> &_fvalue,
                                     std::vector<Real> &initilal,
                                     Real x=0.0, Real y=0.0) const =0;
 };

class GuessSeidel : public MGLevelOp
{
public:
    std::vector<Real> Smooth(  std::vector<Real> &_fvalue,
                               std::vector<Real> &_initial,
                               Real x, Real y) const
                           
  {
    assert(_fvalue.size() == _initial.size());
    std::vector<Real> initial=_initial;
    int n = initial.size();
    Real h = 1.0/(n+1);
    initial[0]=0.5*(initial[1]+_fvalue[0]*h*h+x);
   
    for(int i=1; i< n-1; i++)
      initial[i]=(0.5*initial[i-1]+0.5*initial[i+1]+0.5*h*h*_fvalue[i]);
    initial[n-1]=(0.5*initial[n-2]+0.5*h*h*_fvalue[n-1]+0.5*y);

    return initial; 
  }
};

  class Jacobi : public MGLevelOp
{
public:
    std::vector<Real> Smooth(  std::vector<Real> &_fvalue,
                               std::vector<Real> &initial,
                               Real x, Real y) const
                           
  {
    assert(_fvalue.size() == initial.size());
    std::vector<Real> result;
    int n = initial.size();
    Real h = 1.0/(n+1);
      result.push_back(0.5*(initial[1]+_fvalue[0]*h*h+x));
    for(int i=1; i< n-1; i++)
      result.push_back((0.5*(initial[i-1]+initial[i+1]+h*h*_fvalue[i])));
    result.push_back(0.5*(initial[n-2]+_fvalue[n-1]*h*h+y));
    assert(initial.size()== _fvalue.size());
    return result; 
  }

};

class Bottom
{
public:

  virtual std::vector<Real> BottomSolver(int n,
                                         const std::vector<Real> &_fvalue
                                         ) const = 0;
   
};
class BottomDirect : public Bottom
{
public:
  std::vector<Real> BottomSolver(int n,
                                 const std::vector<Real> &_fvalue ) const
  {
    assert(n == 3);
    Real h = 1.0/(n+1);
    std::vector<Real> result;
    result.push_back(0.25*h*h*( 3*_fvalue[0] + 2*_fvalue[1] + _fvalue[2] ));
    result.push_back(0.25*h*h*( 2*_fvalue[0] + 4*_fvalue[1] + 2*_fvalue[2] ));
    result.push_back(0.25*h*h*( _fvalue[0] + 2*_fvalue[1] + 3*_fvalue[2] ));
    assert(result.size() == n);
  return result;
  }
};


class Residual
{
public:
  virtual std::vector<Real> residualGen(  std::vector<Real> &fvalue,
                                          std::vector<Real> &value,
                                          Real x, Real y) const =0;  
};

class Resi : public Residual
{
public:
  std::vector<Real> residualGen(  std::vector<Real> &fvalue,
                                  std::vector<Real> &value,
                                  Real x, Real y) const
  {
    assert( fvalue.size() == value.size());
       
    int n = fvalue.size();
    Real h= 1.0/(n+1);
    std::vector<Real> result;
    result.push_back( (2*value[0]-value[1]-x)/(h*h) );
    for(int i=1; i<n-1; i++)
      result.push_back( (2*value[i]-value[i-1]-value[i+1])/(h*h) );
    result.push_back( (2*value[n-1]-value[n-2]-y)/(h*h) );

    for(int i=0; i<n; i++)
      result[i] = fvalue[i] - result[i];
    
    return result;
  }
  
};

#endif


