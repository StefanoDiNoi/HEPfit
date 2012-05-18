/* 
 * File:   EWSMThreeLoopEW2QCD.h
 * Author: mishima
 */

#ifndef EWSMTHREELOOPEW2QCD_H
#define	EWSMTHREELOOPEW2QCD_H

#include "EWSMcache.h"
using namespace gslpp;


class EWSMThreeLoopEW2QCD {

public:
 
    /**
     * @brief EWSMThreeLoopEW2QCD constructor
     * @param[in] cache_i reference to an EWSMcommon object
     */
    EWSMThreeLoopEW2QCD(const EWSMcache& cache_i);

    
    ////////////////////////////////////////////////////////////////////////
    
    /**
     * @brief leptonic contribution to alpha
     * @return Delta alpha_{lept}^{alpha^2 alpha_s}
     */
    double DeltaAlpha_l() const;

    /**
     * @brief top-quark contribution to alpha
     * @return Delta alpha_{top}^{alpha^2 alpha_s}
     */
    double DeltaAlpha_t() const;
    
    /**
     * @brief leading contribution to Delta r
     * @param[in] Mw_i the W-boson mass
     * @return Delta rho^{alpha^2 alpha_s}
     */
    double DeltaRho(const double Mw_i) const;

    /**
     * @brief remainder contribution to Delta r
     * @param[in] Mw_i the W-boson mass
     * @return Delta r_{rem}^{alpha^2 alpha_s}
     */
    double DeltaR_rem(const double Mw_i) const;

    /**
     * @brief remainder contribution to rho_Z^l
     * @param[in] l name of lepton
     * @param[in] Mw_i the W-boson mass
     * @return delta rho_{rem}^{l, alpha^2 alpha_s}
     */
    complex deltaRho_rem_l(const StandardModel::lepton l, const double Mw_i) const;

    /**
     * @brief remainder contribution to rho_Z^q
     * @param[in] q name of quark
     * @param[in] Mw_i the W-boson mass
     * @return delta rho_{rem}^{q, alpha^2 alpha_s}
     */
    complex deltaRho_rem_q(const StandardModel::quark q, const double Mw_i) const;

    /**
     * @brief remainder contribution to kappa_Z^l
     * @param[in] l name of lepton
     * @param[in] Mw_i the W-boson mass
     * @return delta kappa_{rem}^{l, alpha^2 alpha_s}
     */
    complex deltaKappa_rem_l(const StandardModel::lepton l, const double Mw_i) const;
                                                  
    /**
     * @brief remainder contribution to kappa_Z^q
     * @param[in] q name of quark
     * @param[in] Mw_i the W-boson mass
     * @return delta kappa_{rem}^{q, alpha^2 alpha_s}
     */
    complex deltaKappa_rem_q(const StandardModel::quark q, const double Mw_i) const;    
    
    
    ////////////////////////////////////////////////////////////////////////        
    
private:
    const EWSMcache& cache;
    

    ////////////////////////////////////////////////////////////////////////    
     
    
};

#endif	/* EWSMTHREELOOPEW2QCD_H */

