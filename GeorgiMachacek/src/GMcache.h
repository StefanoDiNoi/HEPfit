/* 
 * Copyright (C) 2017 HEPfit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef GMCACHE_H
#define	GMCACHE_H

#include "GeorgiMachacek.h"
//#include "RunnerGM.h"

/**
 * @class GMcache
 * @ingroup GeorgiMachacek
 * @brief A class for the caching of %GeorgiMachacek objects.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 */
class GMcache {
    
public:

    /**
     * @brief GMcache constructor.
     * @details Reads all the tables values and stores them in the memory.
     */
    GMcache(const StandardModel& SM_i);

    /**
     * @brief GMcache destructor.
     */
    ~GMcache();

    double updateCache();

//    double Q_cutoff;
//    double g1_at_Q;
//    double g2_at_Q;
//    double g3_at_Q;
//    double Ytop_at_Q;
//    double Ybottom1_at_Q;
//    double Ybottom2_at_Q;
//    double Ytau1_at_Q;
//    double Ytau2_at_Q;
//    double lambda1_at_Q;
//    double lambda2_at_Q;
//    double lambda3_at_Q;
//    double lambda4_at_Q;
//    double mu1_at_Q;
//    double mu3_at_Q;
//    double mu4_at_Q;
//    double nu1_at_Q;
//    double omega1_at_Q;
//    double kappa1_at_Q;
//    double nu2_at_Q;
//    double omega2_at_Q;
//    double kappa2_at_Q;
//    double nu4_at_Q;
//    double omega4_at_Q;
//    double m12sq;
//    double m11sq;
//    double m22sq;
//    double mhsq;
//    double mHsq;
//    double mAsq;
//    double mSRsq;
//    double mSIsq;
//    double mHpsq;
//    double mSpsq;

//    double RpepsGM;
    gslpp::vector<gslpp::complex> unitarityeigenvalues;
//    gslpp::vector<gslpp::complex> NLOunitarityeigenvalues;

    double rh_ff, rh_VV, rh_gg, rh_gaga, rh_Zga;
    double sumModBRs, Gamma_h;//GM_BR_h_bb, GM_BR_h_gaga, GM_BR_h_tautau, GM_BR_h_WW, GM_BR_h_ZZ
    double lambda1, lambda2, lambda3, lambda4, lambda5;
    double vPhi, vDelta;
    
protected:

private:

    const GeorgiMachacek * myGM;
//    RunnerGM * myRunnerGM;

    /**
     * @brief Cache size.
     * @details Determines the size of the cache. If it is set to 5, the cache will remember the last five function calls and store their results.
     */
    static const int CacheSize = 5;

    /**
     * @brief Check whether for the latest set of parameters a value is in the cache.
     * @details Takes a complex value.
     */
    int CacheCheck(const gslpp::complex cache[][CacheSize],
                   const int NumPar, const double params[]) const;

    /**
     * @brief Check whether for the latest set of parameters a value is in the cache.
     * @details Takes a real value.
     */
//    int CacheCheckReal(const double cache[][CacheSize],
//                   const int NumPar, const double params[]) const;

    /**
     * @brief Adds a new result and its parameters into the cache.
     * @details The new values are added on top. The oldest set on the stack is deleted. Takes a complex value.
     */
    void CacheShift(gslpp::complex cache[][CacheSize], const int NumPar,
                    const double params[], const gslpp::complex newResult) const; 

    /**
     * @brief Adds a new result and its parameters into the cache.
     * @details The new values are added on top. The oldest set on the stack is deleted. Takes a real value.
     */
//    void CacheShiftReal(double cache[][CacheSize], const int NumPar,
//                    const double params[], const double newResult) const; 

    gslpp::complex I_h_U(const double mHl2, const double Mu, const double Mc, const double Mt) const;
    gslpp::complex I_HH_U(const double mHh2, const double Mc, const double Mt) const;
    gslpp::complex I_A_U(const double mA2, const double Mc, const double Mt) const;
    gslpp::complex I_h_D(const double mHl2, const double Md, const double Ms, const double Mb) const;
    gslpp::complex I_HH_D(const double mHh2, const double Ms, const double Mb) const;
    gslpp::complex I_A_D(const double mA2, const double Ms, const double Mb) const;
    gslpp::complex I_h_L(const double mHl2, const double Me, const double Mmu, const double Mtau) const;
    gslpp::complex I_HH_L(const double mHh2, const double Mmu, const double Mtau) const;
    gslpp::complex I_A_L(const double mA2, const double Mmu, const double Mtau) const;
    gslpp::complex I_H_W(const double mH, const double MW) const;
    gslpp::complex I_H_Hp(const double mHp2, const double mH) const;

    gslpp::complex A_h_U(const double mHl2, const double cW2, const double Mu, const double Mc, const double Mt, const double MZ) const;
    gslpp::complex A_HH_U(const double mHh2, const double cW2, const double Mc, const double Mt, const double MZ) const;
    gslpp::complex A_A_U(const double mA2, const double cW2, const double Mc, const double Mt, const double MZ) const;
    gslpp::complex A_h_D(const double mHl2, const double cW2, const double Md, const double Ms, const double Mb, const double MZ) const;
    gslpp::complex A_HH_D(const double mHh2, const double cW2, const double Ms, const double Mb, const double MZ) const;
    gslpp::complex A_A_D(const double mA2, const double cW2, const double Ms, const double Mb, const double MZ) const;
    gslpp::complex A_h_L(const double mHl2, const double cW2, const double Me, const double Mmu, const double Mtau, const double MZ) const;
    gslpp::complex A_HH_L(const double mHh2, const double cW2, const double Mmu, const double Mtau, const double MZ) const;
    gslpp::complex A_A_L(const double mA2, const double cW2, const double Mmu, const double Mtau, const double MZ) const;
    gslpp::complex A_H_W(const double mH, const double cW2, const double MW, const double MZ) const;
    gslpp::complex A_H_Hp(const double mHp2, const double mH, const double cW2, const double MZ) const;

    mutable gslpp::complex I_h_U_cache[5][CacheSize];
    mutable gslpp::complex I_HH_U_cache[4][CacheSize];
    mutable gslpp::complex I_A_U_cache[4][CacheSize];
    mutable gslpp::complex I_h_D_cache[5][CacheSize];
    mutable gslpp::complex I_HH_D_cache[4][CacheSize];
    mutable gslpp::complex I_A_D_cache[4][CacheSize];
    mutable gslpp::complex I_h_L_cache[5][CacheSize];
    mutable gslpp::complex I_HH_L_cache[4][CacheSize];
    mutable gslpp::complex I_A_L_cache[4][CacheSize];
    mutable gslpp::complex I_H_W_cache[3][CacheSize];
    mutable gslpp::complex I_H_Hp_cache[3][CacheSize];

    mutable gslpp::complex A_h_U_cache[7][CacheSize];
    mutable gslpp::complex A_HH_U_cache[6][CacheSize];
    mutable gslpp::complex A_A_U_cache[6][CacheSize];
    mutable gslpp::complex A_h_D_cache[7][CacheSize];
    mutable gslpp::complex A_HH_D_cache[6][CacheSize];
    mutable gslpp::complex A_A_D_cache[6][CacheSize];
    mutable gslpp::complex A_h_L_cache[7][CacheSize];
    mutable gslpp::complex A_HH_L_cache[6][CacheSize];
    mutable gslpp::complex A_A_L_cache[6][CacheSize];
    mutable gslpp::complex A_H_W_cache[5][CacheSize];
    mutable gslpp::complex A_H_Hp_cache[5][CacheSize];

    gslpp::complex f_func(const double x) const;
    gslpp::complex g_func(const double x) const;

    gslpp::complex Int1(const double tau, const double lambda) const;
    gslpp::complex Int2(const double tau, const double lambda) const;

//    void runGMparameters();

    void computeUnitarity();
//    gslpp::vector<gslpp::complex> betaeigenvalues;

    void computeSignalStrengthQuantities();

    double cW2GM(const double c02) const;
    double MWGM(const double MW) const;

//    std::string GMmodel;
    double Q_GM;
    double MZ;
    double vev;
    double mHl;
    double mHl2;
    double tanb;
    double sinb;
    double cosb;
    double sina;
    double cosa;
    double mH1sq;
    double mAsq;
    double mH5sq;
    double Mu1;
    double Mu2;
    double M1sq;
    double M2sq;
    double ghhh;
    double ghhH;
    double ghHH;
    double gHHH;
    double ghH3H3;
    double gHH3H3;
    double ghH3pH3m;
    double gHH3pH3m;
    double ghH5H5;
    double gHH5H5;
    double ghH5pH5m;
    double gHH5pH5m;
    double ghH5ppH5mm;
    double gHH5ppH5mm;
    double gH3H3H5;
    double gH5H5H5;
    gslpp::complex gH3H3pH5m;
    double gH5H3pH3m;
    double gH5H5pH5m;
    double gH5H5ppH5mm;
    double gH5ppH3mH3m;
    double gH5ppH5mH5m;
};

#endif	/* GMCACHE_H */