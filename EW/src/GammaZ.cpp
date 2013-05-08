/* 
 * Copyright (C) 2012-2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#include "GammaZ.h"


double GammaZ::getThValue() 
{ 
    double Gamma_Z;
    EW::EWTYPE myEWTYPE = myEW.getEWTYPE();

    if (myEWTYPE==EW::EWCHMN)  
        Gamma_Z = myEW.getMyEW_CHMN().GammaZ();
    else if (myEWTYPE==EW::EWABC) 
        Gamma_Z = myEW.getMyEW_ABC().GammaZ(SM.epsilon1(),SM.epsilon3(),SM.epsilonb());
    else if (myEWTYPE==EW::EWABC2) {
        double delta_als = (SM.Als(SM.getMz(),FULLNNLO) - 0.119)/M_PI;
        double delta_alpha = (SM.alphaMz() - 1.0/128.90)/SM.getAle();
        double Gamma_T0 = 2.48946*(1.0 + 0.73*delta_als - 0.35*delta_alpha);
        Gamma_Z = Gamma_T0*(1.0 + 1.35*SM.epsilon1() - 0.46*SM.epsilon3() + 0.35*SM.epsilonb());
    } else {
        Gamma_Z = myEW.Gamma_Z();

        if ( myEW.checkModelForSTU() ) {
            if(myEWTYPE==EW::EWBURGESS) {
                // TEST: the fit result by Gfitter in arXiv:1209.2716, 
                //       corresponding to MH=125.7 and Mt=173.52 
                //Gamma_Z = 2.4954; 

                Gamma_Z += - 0.00961*myEW.S() + 0.0263*myEW.T();
            } else {
                double alpha = myEW.alpha();  
                double c2 = myEW.cW2_SM();
                double s2 = myEW.sW2_SM();
                double s4 = s2*s2;
                
                Gamma_Z += alpha*alpha*SM.getMz()/72.0/c2/s2/(c2-s2)
                           *( -10.0*(3.0-8.0*s2)*myEW.S() 
                              + (63.0-126.0*s2-40.0*s4)*myEW.T() );
            }
        }
        
        if (SM.IsFlagNPZbbbarLinearize() && (SM.deltaGVb()!=0.0 || SM.deltaGAb()!=0.0) ) {
            double alpha = myEW.alpha();  
            double c2 = myEW.cW2_SM();
            double s2 = myEW.sW2_SM();
            double gVb0 = SM.getQuarks(SM.BOTTOM).getIsospin() 
                          - 2.0*SM.getQuarks(SM.BOTTOM).getCharge()*myEW.sW2_SM();
            double gAb0 = SM.getQuarks(SM.BOTTOM).getIsospin();        
            double Nc = 3.0;
            double coeff = Nc*alpha*SM.getMz()/6.0/s2/c2;
            double coeffV = coeff*gVb0;
            double coeffA = coeff*gAb0;
            //std::cout << "cV: " << coeffV << std::endl;
            //std::cout << "cA: " << coeffA << std::endl;
            //std::cout << "cL: " << coeffV+coeffA << std::endl;
            //std::cout << "cR: " << coeffV-coeffA << std::endl;

            Gamma_Z += coeffV*SM.deltaGVb() + coeffA*SM.deltaGAb();
            
            /* TEST */        
            //double Gamma_b = myEW.Gamma_q(SM.BOTTOM);
            //coeff = 2.0/(gVb0*gVb0 + gAb0*gAb0);
            //coeffV = coeff*gVb0;
            //coeffA = coeff*gAb0;
            //Gamma_Z += Gamma_b*(coeffV*SM.deltaGVb() + coeffA*SM.deltaGAb());  
        }
        
        /* TEST */
        //Gamma_Z -=  myEW.Gamma_Z();
    }
      
    return Gamma_Z;
}
        
