#include "MultigridPossion.h"
#include "Real.h"
#include "Restriction.h"
#include "Interpolation.h"
#include "func.h"
#include "MGLevelOp.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{

   int Test128=0, Test256=0, Test512=0, Test1024=0, Testfull=1;
   int TestLinear=1;
   
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
         // _fvalue.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
          _fvalue.push_back(2.0);
       }
    Quadratic _linear;
     FullWeighting rest;
     Real eps=0.00000000000001;

        cout << left;
        cout << setw(8) << "Full-MG "
             << setw(4) << "|"
          << setw(9) << "n=128 "
             << setw(18) << "n=256 "
             <<setw(18)<< "n=512"
             << setw(18)<< "n= 1024"<< endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "nu_0"<<  setw(4) << "|"<<setw(9)<<"error"
             <<  setw(9) << "error"<<  setw(9) << "rate"
         <<  setw(9) << "error"<<  setw(9) << "rate" <<  setw(9) << "error"
          <<  setw(9) << "rate"
           <<endl;

       

        Real resilast, errorlast;
            if ( Testfull == true)
          {
            //std::vector<Real>  v=mul2.Vcycle(128,_fvalue,rest,_linear,2,2,guess_2);
             std::vector<Real> _fvalue128;
            std::vector<Real> _fvalue256;
            std::vector<Real> _fvalue512;
            std::vector<Real> _fvalue1024;

              for(int i=1; i<128; i++)
       {
         double x = i*(1.0/128);
         _fvalue128.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
         //  _fvalue128.push_back(2.0);
       }
            for(int i=1; i<256; i++)
       {
         double x = i*(1.0/256);
         _fvalue256.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
         //  _fvalue256.push_back(2.0);
       }
            for(int i=1; i<512; i++)
       {
         double x = i*(1.0/512);
         _fvalue512.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
//           _fvalue512.push_back(2.0);
       }
            for(int i=1; i<1024; i++)

        {
         double x = i*(1.0/1024);
         _fvalue1024.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
         // _fvalue1024.push_back(2.0);
       }
            MultigridPossion mul128(1.0 ,exp(sin(1)), 20, 128, 0.00000001);
           MultigridPossion mul256(1.0 , exp(sin(1)), 20, 256, 0.00000001);
           MultigridPossion mul512(1.0 , exp(sin(1)), 20, 512, 0.00000001);
        MultigridPossion mul1024(1.0 , exp(sin(1)), 20, 1024, 0.00000001);
            
            for(int k =2; k< 20; k++)
              {
        std::vector<Real>  f128=mul2.Full(128,_fvalue128,rest,_linear,2,2,k);
        std::vector<Real>  f256=mul256.Full(256,_fvalue256,rest,_linear,2,2,k);
         std::vector<Real>  f512=mul512.Full(512,_fvalue512,rest,_linear,2,2,k);
          std::vector<Real>  f1024=mul1024.Full(1024,_fvalue1024,rest,_linear,2,2,k);
                std::vector<Real> _result128;
     
                for(int i=0; i<127; i++ )
                  {
                    double x= (i+1)*1.0/128;
                   _result128.push_back(fabs( exp(sin( (i+1) * (1.0/128) ))-f128[i]) );
                  //_result.push_back(fabs( x*(1-x)-f128[i]) );
                  }
                double resi=_result128[0];
                for(int i=1; i< 127; i++)
                  resi = _result128[i]> resi? _result128[i] : resi;

                 std::vector<Real> _result256;
     
                for(int i=0; i<255; i++ )
                  {
                    double x= (i+1)*1.0/256;
                   _result256.push_back(fabs( exp(sin( (i+1) * (1.0/256) ))-f256[i]) );
                    //  _result256.push_back(fabs( x*(1-x)-f256[i]) );
                  }
                double resi256=_result256[0];
                for(int i=1; i< 255; i++)
                  resi256 = _result256[i]> resi256? _result256[i] : resi256;
                  std::vector<Real> _result512;
     
                  for(int i=0; i<511; i++ ){
                    double x= (i+1)*1.0/512;
                   _result512.push_back(fabs( exp(sin( (i+1) * (1.0/512) ))-f512[i]) );
                   // _result512.push_back(fabs( x*(1-x)-f512[i]) );
                  }
                double resi512=_result512[0];
                for(int i=1; i< 511; i++)
                  resi512 = _result512[i]> resi512? _result512[i] : resi512;
                   std::vector<Real> _result1024;
     
                   for(int i=0; i<1023; i++ ){
                     double x= (i+1)*1.0/1024;
                     _result1024.push_back(fabs( exp(sin((i+1)*(1.0/1024) ))-f1024[i]) );
                     // _result1024.push_back(fabs( x*(1-x)-f1024[i]) );
                   }
                double resi1024=_result1024[0];
                for(int i=1; i< 1024; i++)
                  resi1024 = _result1024[i]> resi1024? _result1024[i] : resi1024;

                 
                 cout << setw(8) << k
                     << setw(4) << "|";
                 cout<<  setw(9)
                    << setprecision(2)
                     <<scientific<<resi;
                cout<<  setw(9)<< setprecision(2)
                    <<scientific <<resi256 <<setw(9)<<fixed
                    <<log(resi/resi256)/log(2);
                 cout<<  setw(9) << setprecision(2)<<scientific <<resi512
                     <<setw(9) <<fixed
                    <<log(resi256/resi512)/log(2);
                  cout<<  setw(9) << setprecision(2)<<scientific <<resi1024
                     <<setw(9) <<fixed
                    <<log(resi512/resi1024)/log(2);

                cout<< endl;
              }
          }
 

              if ( Test256 == true)
          {
              cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 256" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
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
                  
                     
                cout << setw(8) << k
                     << setw(4) << "|"
                   << setw(18)
                     <<scientific
                     << setprecision(2)
                     <<dec <<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)
                     <<fixed
                      << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<resi;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                      <<fixed
                      << setprecision(2)
                      <<resi/errorlast;
                 errorlast = resi;
                cout<< endl;

                  if (temp < 0.00000001)
                  break;
                 v256=mul256.Vcycle(256,_fvalue,rest,_linear,2,2,v256);
              
              }
          }

                 if ( Test512 == true)
          {
              cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 512" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue512;
                for(int i=1; i<512; i++)
       {
         double x = i*(1.0/512);
         _fvalue512.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
       }
                _fvalue= _fvalue512;
             MultigridPossion mul512(1.0 , x, 20, 512, 0.00000001);
             std::vector<Real> guess512(511,0.0);
            std::vector<Real>  v512=mul512.Vcycle(512,_fvalue,rest,_linear,2,2,guess512);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v512.size(); i++ )
                  _result.push_back(fabs( exp(sin( (i+1) * (1.0/512) ))-v512[i]) );
                double resi=_result[0];
                for(int i=1; i< v512.size(); i++)
                  resi = _result[i]> resi? _result[i] : resi;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v512, 1.0, exp(sin(1.0)));
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                  
                           
                cout << setw(8) << k
                     << setw(4) << "|"
                   << setw(18)
                     <<scientific
                     << setprecision(2)
                     <<dec <<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)
                     <<fixed
                      << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<resi;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                      <<fixed
                      << setprecision(2)
                      <<resi/errorlast;
                 errorlast = resi;
                cout<< endl;
                 if (temp < 0.00000001)
                  break;

                 v512=mul512.Vcycle(512,_fvalue,rest,_linear,2,2,v512);
              
              }
          }

                 
                 if ( Test1024 == true)
          {
              cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 1024" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue1024;
                for(int i=1; i<1024; i++)
       {
         double x = i*(1.0/1024);
         _fvalue1024.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
       }
                _fvalue= _fvalue1024;
             MultigridPossion mul1024(1.0 , x, 20, 1024, 0.00000001);
             std::vector<Real> guess1024(1023,0.0);
            std::vector<Real>  v1024=mul1024.Vcycle(1024,_fvalue,rest,_linear,2,2,guess1024);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v1024.size(); i++ )
                  _result.push_back(fabs( exp(sin( (i+1) * (1.0/1024) ))-v1024[i]) );
                double resi=_result[0];
                for(int i=1; i< v1024.size(); i++)
                  resi = _result[i]> resi? _result[i] : resi;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v1024, 1.0, exp(sin(1.0)));
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
             
                           
                cout << setw(8) << k
                     << setw(4) << "|"
                   << setw(18)
                     <<scientific
                     << setprecision(2)
                      <<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)
                     <<fixed
                      << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<resi;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                      <<fixed
                      << setprecision(2)
                      <<resi/errorlast;
                 errorlast = resi;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v1024=mul1024.Vcycle(1024,_fvalue,rest,_linear,2,2,v1024);
              
              }
          }

                               if ( Test128 == true)
          {
              cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 128" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue128;
                for(int i=1; i<128; i++)
       {
         double x = i*(1.0/128);
         _fvalue128.push_back(-(cos(x)*cos(x)-sin(x))*exp(sin(x)));
       }
                _fvalue= _fvalue128;
             MultigridPossion mul128(1.0 , x, 20, 128, 0.00000001);
             std::vector<Real> guess128(127,0.0);
            std::vector<Real>  v128=mul128.Vcycle(128,_fvalue,rest,_linear,2,2,guess128);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v128.size(); i++ )
                  _result.push_back(fabs( exp(sin( (i+1) * (1.0/128) ))-v128[i]) );
                double resi=_result[0];
                for(int i=1; i< v128.size(); i++)
                  resi = _result[i]> resi? _result[i] : resi;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v128, 1.0, exp(sin(1.0)));
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
             
                           
                cout << setw(8) << k
                     << setw(4) << "|"
                   << setw(18)
                     <<scientific
                     << setprecision(2)
                      <<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)
                     <<fixed
                      << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<resi;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                      <<fixed
                      << setprecision(2)
                      <<resi/errorlast;
                 errorlast = resi;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v128=mul128.Vcycle(128,_fvalue,rest,_linear,2,2,v128);
              
              }
          }

   int linearTest128=1, linearTest256=1,linearTest512=1,linearTest1024=1;
 if(TestLinear ==1){
      if(linearTest128==1){
             cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 128" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue128;
                for(int i=1; i<128; i++)
       {
         double x = i*(1.0/128);
         // _fvalue128.push_back(2*cos(x*(1-x))+ (1-2*x)*(1-2*x)*sin(x*(1-x)));
         //_fvalue128.push_back(x*(3+x)*exp(x));
         _fvalue128.push_back(2.0);
         
       }
                _fvalue= _fvalue128;
                MultigridPossion mul128(0.0 , 0.0, 20, 128, 0.00000001);
             std::vector<Real> guess128(127,0.0);
            std::vector<Real>  v128=mul128.Vcycle(128,_fvalue128,rest,_linear,2,2,guess128);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v128.size(); i++ )
                  {
                    Real x= (i+1)*1.0/128;
                    // _result.push_back(fabs( exp(x)*(x*(1-x))-v128[i]));
                     _result.push_back(fabs( (x*(1-x))-v128[i]));
                  }
                double error=_result[0];
                for(int i=1; i< v128.size(); i++)
                  error = _result[i]> error? _result[i] : error;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v128, 0.0, 0.0);
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                                  
                cout << setw(8) << k<< setw(4) << "|"
                   << setw(18)<<scientific<< setprecision(2)<<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)<<fixed << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<error;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)<<fixed<< setprecision(2)
                      <<error/errorlast;
                 errorlast = error;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v128=mul128.Vcycle(128,_fvalue,rest,_linear,2,2,v128);
              }
              }

   if(linearTest256==1){
             cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 256" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue256;
                for(int i=1; i<256; i++)
       {
         double x = i*(1.0/256);
         // _fvalue256.push_back(2*cos(x*(1-x))+ (1-2*x)*(1-2*x)*sin(x*(1-x)));
         //_fvalue256.push_back(x*(3+x)*exp(x));
         _fvalue256.push_back(2.0);
         
       }
                _fvalue= _fvalue256;
                MultigridPossion mul256(0.0 , 0.0, 20, 256, 0.00000001);
             std::vector<Real> guess256(255,0.0);
            std::vector<Real>  v256=mul256.Vcycle(256,_fvalue256,rest,_linear,2,2,guess256);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v256.size(); i++ )
                  {
                    Real x= (i+1)*1.0/256;
                    // _result.push_back(fabs( exp(x)*(x*(1-x))-v256[i]));
                     _result.push_back(fabs( (x*(1-x))-v256[i]));
                  }
                double error=_result[0];
                for(int i=1; i< v256.size(); i++)
                  error = _result[i]> error? _result[i] : error;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v256, 0.0, 0.0);
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                                  
                cout << setw(8) << k<< setw(4) << "|"
                   << setw(18)<<scientific<< setprecision(2)<<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)<<fixed << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<error;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)<<fixed<< setprecision(2)
                      <<error/errorlast;
                 errorlast = error;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v256=mul256.Vcycle(256,_fvalue,rest,_linear,2,2,v256);
              }
              }


   if(linearTest512==1){
             cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 512" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue512;
                for(int i=1; i<512; i++)
       {
         double x = i*(1.0/512);
         // _fvalue512.push_back(2*cos(x*(1-x))+ (1-2*x)*(1-2*x)*sin(x*(1-x)));
         //_fvalue512.push_back(x*(3+x)*exp(x));
         _fvalue512.push_back(2.0);
         
       }
                _fvalue= _fvalue512;
                MultigridPossion mul512(0.0 , 0.0, 20, 512, 0.00000001);
             std::vector<Real> guess512(511,0.0);
            std::vector<Real>  v512=mul512.Vcycle(512,_fvalue512,rest,_linear,2,2,guess512);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v512.size(); i++ )
                  {
                    Real x= (i+1)*1.0/512;
                    // _result.push_back(fabs( exp(x)*(x*(1-x))-v512[i]));
                     _result.push_back(fabs( (x*(1-x))-v512[i]));
                  }
                double error=_result[0];
                for(int i=1; i< v512.size(); i++)
                  error = _result[i]> error? _result[i] : error;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v512, 0.0, 0.0);
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                                  
                cout << setw(8) << k<< setw(4) << "|"
                   << setw(18)<<scientific<< setprecision(2)<<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)<<fixed << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<error;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)<<fixed<< setprecision(2)
                      <<error/errorlast;
                 errorlast = error;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v512=mul512.Vcycle(512,_fvalue,rest,_linear,2,2,v512);
              }
              }

   if(linearTest1024==1){
             cout << left;
        cout << setw(8) << " "
             << setw(30) << "|" << setw(36) << "n = 1024" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout <<  setw(8)<< "V-cycle"
             <<  setw(4) << "|"
             <<  setw(18) << "residual"
          <<  setw(18) << "ratio"
          <<  setw(18) << "error"
             <<  setw(18) << "ratio"<<endl;
            
            std::vector<Real> _fvalue1024;
                for(int i=1; i<1024; i++)
       {
         double x = i*(1.0/1024);
         // _fvalue1024.push_back(2*cos(x*(1-x))+ (1-2*x)*(1-2*x)*sin(x*(1-x)));
         //_fvalue1024.push_back(x*(3+x)*exp(x));
         _fvalue1024.push_back(2.0);
         
       }
                _fvalue= _fvalue1024;
                MultigridPossion mul1024(0.0 , 0.0, 20, 1024, 0.00000001);
             std::vector<Real> guess1024(1023,0.0);
            std::vector<Real>  v1024=mul1024.Vcycle(1024,_fvalue1024,rest,_linear,2,2,guess1024);
            for(int k =0; k< 15; k++)
              {
                      
                std::vector<Real> _result;
     
                for(int i=0; i<v1024.size(); i++ )
                  {
                    Real x= (i+1)*1.0/1024;
                    // _result.push_back(fabs( exp(x)*(x*(1-x))-v1024[i]));
                     _result.push_back(fabs( (x*(1-x))-v1024[i]));
                  }
                double error=_result[0];
                for(int i=1; i< v1024.size(); i++)
                  error = _result[i]> error? _result[i] : error;

                Resi re;
                std::vector<Real> r =re.residualGen(_fvalue, v1024, 0.0, 0.0);
                Real relative ;
                relative = fabs(_fvalue[0]);
                for(int i=1; i<r.size(); i++)
                  relative = relative > fabs(_fvalue[i])? relative: fabs(_fvalue[i]);
                   
                  
                Real temp=fabs(r[0]);
                for(int i=1; i<r.size(); i++)
                  temp = fabs(r[i])< temp? temp: fabs(r[i]);
                                  
                cout << setw(8) << k<< setw(4) << "|"
                   << setw(18)<<scientific<< setprecision(2)<<temp;
               
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)
                    << setprecision(2)<<fixed << temp/resilast;
                 resilast = temp;
                cout   << setw(18)<< setprecision(2) << scientific<<error;
                  
                if(k == 0)
                  cout<< setw(18)<<" ";
                else
                  cout<< setw(18)<<fixed<< setprecision(2)
                      <<error/errorlast;
                 errorlast = error;
                cout<< endl;
                 if (temp/relative < 0.00000001)
                  break;

                 v1024=mul1024.Vcycle(1024,_fvalue,rest,_linear,2,2,v1024);
              }
              }
   
 }// TestLinear
         
    return 0;
  }



