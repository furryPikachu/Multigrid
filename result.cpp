#include "MultigridPossion.h"
#include "Real.h"
#include "Restriction.h"
#include "Interpolation.h"
#include "func.h"
#include "MGLevelOp.h"
#include "iomanip"
using namespace std;

int main(int argc, char *argv[])
{
  double x=exp(sin(1));
  MultigridPossion mul2(1.0 , x, 20, 128, 0.00000001);
    
     std::vector<Real> guess_2(127, 0);
     assert(guess_2.size() == 127);
     // mul.boundary.push_back(0);
     // std::cout << (mul.boundary)[1];
     func1 _f;
     mul2.generatFuncValue(_f);
     std::vector<Real> _fvalue;
     for(int i=1; i<128; i++)
       {
         double x = i*(1.0/128);
         _fvalue.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
       }
     Linear _linear;
     FullWeighting rest;


        // bool TestLinear = false;
        // if(TestLinear == true)
        //   {
        //     MultigridPossion test3(0.0 ,1.0, 6, 64, 0.0000001);
        //     std::vector<Real> _f;
     
        //     for(int i=1; i<64; i++ )
        //       _f.push_back(i*(1.0/64));
        //     std::vector<Real> init(63,0);
        //     std::vector<Real>  v3=test3.Vcycle(64,init,rest,_linear,2,2,init);
        //     for(int k =0; k<4; k++)
        //       v3=test3.Vcycle(64,init,rest,_linear,2,2,v3);
            
        //      for(int i=0; i<64;i++)
        //        std::cout<<v3[i]<<", "<<std::endl;
        //   }
        
        cout << left;
        cout << setw(6) << " "
             << setw(16) << "|"
             << setw(20) << "n = 128"
             << setw(16) << "|"
             << setw(20) << "n = 256"
             << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(6)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(9) << "residual"
          <<  setw(9) << "ratio"
          <<  setw(9) << "error"
             <<  setw(9) << "ratio"<<endl;

        int Test128, Test256=1, Test512=1, Test1024=1;
        Test128=true;
        if ( Test128 == true)
          {
            std::vector<Real>  v=mul2.Vcycle(128,_fvalue,rest,_linear,2,2,guess_2);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v.size(); i++ )
                  _result.push_back(fabs( exp(sin( (i+1) * (1.0/128) ))-v[i]) );
                double resi=_result[0];
                for(int i=1; i< v.size()+1; i++)
                  resi = _result[i]> resi? _result[i] : resi;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v, 1.0, exp(sin(1.0)));
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                  
                cout<< v.size()<< endl;
                for(int j =0; j<v.size(); j++)
                  cout<< v[j]- exp(sin( (j+1) * (1.0/128) ))<<",  ";
                cout<< endl;
                  
                v=mul2.Vcycle(128,_fvalue,rest,_linear,2,2,v);

                cout << setprecision(4);
                cout << setw(6) << k
                     << setw(6) << "|"
                     << setw(12) << resi
                     << setw(12)  << temp<< endl;
              }
          }

              if ( Test256 == true)
          {
            std::vector<Real> _fvalue256;
                for(int i=1; i<256; i++)
       {
         double x = i*(1.0/256);
         _fvalue256.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
       }
                _fvalue= _fvalue256;
             MultigridPossion mul256(1.0 , x, 20, 256, 0.00000001);
             std::vector<Real> guess256(255,0.0);
            std::vector<Real>  v256=mul256.Vcycle(256,_fvalue,rest,_linear,2,2,guess256);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v256.size(); i++ )
                  _result.push_back(fabs( exp(sin( (i+1) * (1.0/256) ))-v256[i]) );
                double resi=_result[0];
                for(int i=1; i< v256.size(); i++)
                  resi = _result[i]> resi? _result[i] : resi;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v256, 1.0, exp(sin(1.0)));
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                  
                cout<< v256.size()<< endl;
                for(int j =0; j<v256.size(); j++)
                  cout<< v256[j]- exp(sin( (j+1) * (1.0/256) ))<<",  ";
                cout<< endl;
                  
                v256=mul256.Vcycle(256,_fvalue,rest,_linear,2,2,v256);

                cout << setprecision(4);
                cout << setw(6) << k
                     << setw(6) << "|"
                     << setw(12) << resi
                     << setw(12)  << temp<< endl;
              }
          }
         
    return 0;
  }



