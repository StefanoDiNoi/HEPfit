/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include <Math/Functor.h>
#include <Math/Integrator.h>
#include <Math/AllIntegrationTypes.h>
#include "LEP2AFBcharm.h"


double LEP2AFBcharm::computeThValue() 
{ 
    Mw = SM.Mw(); 
    GammaZ = SM.Gamma_Z();

    if (!checkSMparams(s, Mw, GammaZ)) {        
        mq_cache = m_q(SM.CHARM, sqrt_s);

        double AFB_noBox, sigma = 0.0;
        if (!flag[ISR])
            AFB_noBox = AFB_NoISR_q();
        else {
            ROOT::Math::Functor1D wf(this, &LEP2AFBcharm::Integrand_AFBnumeratorWithISR_q);
            ROOT::Math::Integrator ig(wf, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig.SetAbsTolerance(1.E-14); // desired absolute error
            ig.SetRelTolerance(1.E-4); // desired relative error
            double numerator = ig.Integral(0.0, 1.0-0.85*0.85); // interval
            //std::cout << numerator << " +- " << ig.Error() << std::endl;
            // results: 7.5e-9 -- 3.0e-8
            
            // denominator
            myLEP2sigmaCharm.setFlags(flag);
            sigma = myLEP2sigmaCharm.computeThValue()/SM.GeVminus2_to_nb/1000.0;
            
            AFB_noBox = numerator/sigma;
        }
        SMresult_cache = AFB_noBox;
        
        if (flag[WeakBox]) {
            // numerator
            ROOT::Math::Functor1D wf_F(this, &LEP2AFBcharm::Integrand_dsigmaBox_q);
            ROOT::Math::Integrator ig_F(wf_F, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig_F.SetAbsTolerance(1.E-16); // desired absolute error
            ig_F.SetRelTolerance(1.E-4); // desired relative error
            double sigma_box_F = ig_F.Integral(0.0, 1.0); // interval
            //std::cout << sigma_box_F << " +- " << ig_F.Error()  << std::endl;
            // results: 8.6e-11 -- 3.1e-10
            //
            ROOT::Math::Functor1D wf_B(this, &LEP2AFBcharm::Integrand_dsigmaBox_q);
            ROOT::Math::Integrator ig_B(wf_B, ROOT::Math::IntegrationOneDim::kADAPTIVESINGULAR);
            ig_B.SetAbsTolerance(1.E-16); // desired absolute error
            ig_B.SetRelTolerance(1.E-4); // desired relative error
            double sigma_box_B = ig_B.Integral(-1.0, 0.0); // interval
            //std::cout << sigma_box_B << " +- " << ig_B.Error()  << std::endl;
            // results: 5.0e-11 -- 8.5e-11
                        
            // denominator
            if (!flag[ISR]) {
                myLEP2sigmaCharm.setFlags(flag);
                sigma = myLEP2sigmaCharm.computeThValue()/SM.GeVminus2_to_nb/1000.0;
            }
            
            SMresult_cache += (sigma_box_F - sigma_box_B)/sigma;
        }
    }
    double AFB_c = SMresult_cache;
    
    #ifdef LEP2TEST
    AFB_c = myTEST.AFBcharmTEST(sqrt_s);
    #endif
        
    if ( checkLEP2NP() ) {
        double obliqueShat = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueShat();
        double obliqueThat = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueThat();
        double obliqueUhat = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueUhat();
        double obliqueV = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueV();
        double obliqueW = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueW();
        double obliqueX = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueX();
        double obliqueY = (dynamic_cast<const NPSTUVWXY*> (&SM))->obliqueY();
        double ObParam[7] = {obliqueShat, obliqueThat, obliqueUhat,
                             obliqueV, obliqueW, obliqueX, obliqueY};
        AFB_c += myLEP2oblique.AFB_q_LEP2_NP(QCD::CHARM, s, mq_cache, ObParam);
    }
    
    if ( checkLEP2GIMR() ) {
        double deltaAFB = 0., sigma = 0.0,dFminusB =0.0;
        double myCLL = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->CLL_charm();
        double myCLR = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->CRL_charm();
        double myCRL = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->CRL_charm();
        double myCRR = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->CRR_charm();
        
        double deltaGammaZ = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaGamma_Z();
        double deltaGR_l = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaGR_f(SM.getQuarks(StandardModel::CHARM));
        double deltaGL_l = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaGL_f(SM.getQuarks(StandardModel::CHARM));
        double deltaGR_e = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaGR_f(SM.getLeptons(StandardModel::ELECTRON));
        double deltaGL_e = (dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaGL_f(SM.getLeptons(StandardModel::ELECTRON));
        double deltaMz2=(dynamic_cast<const NPEffectiveGIMR*> (&SM))->deltaMz2();
        
        double GIMRParam[10] ={myCLL,myCLR,myCRL,myCRR,deltaGammaZ,deltaGL_l,deltaGR_l,deltaGL_e,deltaGR_e,deltaMz2};
        
        myLEP2sigmaCharm.setFlags(flag);
        sigma = myLEP2sigmaCharm.computeThValue()/SM.GeVminus2_to_nb/1000.0;
        dFminusB = (myLEP2GIMR.sigmaF_q_LEP2_GIMR(StandardModel::CHARM, s, GIMRParam)
                    -myLEP2GIMR.sigmaB_q_LEP2_GIMR(StandardModel::CHARM, s, GIMRParam));
        
        deltaAFB = AFB_c*(1-myLEP2GIMR.sigma_q_LEP2_GIMR(StandardModel::CHARM, s, GIMRParam)/sigma)+dFminusB/sigma;
        
        AFB_c += deltaAFB;
    }

    return AFB_c;
}
        


