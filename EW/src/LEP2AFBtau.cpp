/* 
 * Copyright (C) 2012-2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#include <Math/Functor.h>
#include <Math/Integrator.h>
#include <Math/AllIntegrationTypes.h>
#include "LEP2AFBtau.h"


double LEP2AFBtau::getThValue() 
{ 
    Mw = SM.Mw(); 
    GammaZ = myEW.Gamma_Z();

    if (!checkSMparams(s, Mw, GammaZ)) {
        ml_cache = m_l(SM.TAU);

        double AFB_noBox, sigma;
        if (!flag[ISR])
            AFB_noBox = AFB_NoISR_l();
        else {
            // numerator
            ROOT::Math::Functor1D wf(this, &LEP2AFBtau::Integrand_AFBnumeratorWithISR_l);
            ROOT::Math::Integrator ig(wf, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig.SetAbsTolerance(1.E-14); // desired absolute error
            ig.SetRelTolerance(1.E-4); // desired relative error
            double numerator = ig.Integral(0.0, 1.0-0.85*0.85); // interval
            //std::cout << numerator << " +- " << ig.Error() << std::endl;
            // results: 3.7e-9 -- 1.5e-8
            
            // denominator
            myLEP2sigmaTau.setFlags(flag);
            sigma = myLEP2sigmaTau.getThValue()/GeVminus2_to_nb/1000.0;
            
            AFB_noBox = numerator/sigma;
        }    
        SMresult_cache = AFB_noBox;
        
        if (flag[WeakBox]) {
            // numerator
            ROOT::Math::Functor1D wf_F(this, &LEP2AFBtau::Integrand_dsigmaBox_l);
            ROOT::Math::Integrator ig_F(wf_F, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig_F.SetAbsTolerance(1.E-17); // desired absolute error
            ig_F.SetRelTolerance(1.E-4); // desired relative error
            double sigma_box_F = ig_F.Integral(0.0, 1.0); // interval
            //std::cout << sigma_box_F << " +- " << ig_F.Error()  << std::endl;
            // results: 6.0e-12 -- 2.0e-10
            //
            ROOT::Math::Functor1D wf_B(this, &LEP2AFBtau::Integrand_dsigmaBox_l);
            ROOT::Math::Integrator ig_B(wf_B, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig_B.SetAbsTolerance(1.E-18); // desired absolute error
            ig_B.SetRelTolerance(1.E-4); // desired relative error
            double sigma_box_B = ig_B.Integral(-1.0, 0.0); // interval
            //std::cout << sigma_box_B << " +- " << ig_B.Error()  << std::endl;
            // results: 3.4e-13 -- 8.7e-11
            
            // denominator
            if (!flag[ISR]) {
                myLEP2sigmaTau.setFlags(flag);
                sigma = myLEP2sigmaTau.getThValue()/GeVminus2_to_nb/1000.0;
            }
            
            SMresult_cache += (sigma_box_F - sigma_box_B)/sigma;
        }

        if ( myEW.checkModelForSTU() && SM.IsFlagFixedAllSMparams() ) {
            double ObParam[7];
            for (int i=0; i<7; i++) {
                SetObParam((LEP2oblique::Oblique)i, ObParam);
                Coeff_cache[i] 
                    = myLEP2oblique.AFB_l_LEP2_NP(SM.TAU, s, ml_cache, ObParam);
            }
        }
    }
    double AFB_tau = SMresult_cache;
    
    #ifdef LEP2TEST
    AFB_tau = myTEST.AFBtauTEST(sqrt_s);
    #endif
            
    if ( myEW.checkModelForSTU() ) {
        if ( SM.IsFlagFixedAllSMparams() ) {
            AFB_tau += Coeff_cache[myLEP2oblique.Shat]*myEW.Shat()
                     + Coeff_cache[myLEP2oblique.That]*myEW.That()
                     + Coeff_cache[myLEP2oblique.Uhat]*myEW.Uhat()
                     + Coeff_cache[myLEP2oblique.V]*myEW.V()
                     + Coeff_cache[myLEP2oblique.W]*myEW.W()
                     + Coeff_cache[myLEP2oblique.X]*myEW.X()
                     + Coeff_cache[myLEP2oblique.Y]*myEW.Y();
        } else {
            double ObParam[7] = {myEW.Shat(), myEW.That(), myEW.Uhat(),
                                 myEW.V(), myEW.W(), myEW.X(), myEW.Y()};
            AFB_tau += myLEP2oblique.AFB_l_LEP2_NP(SM.TAU, s, ml_cache, ObParam);
        }
    }
        
    return AFB_tau;
}
        