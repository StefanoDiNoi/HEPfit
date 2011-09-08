/*
 * File:   StandardModel.h
 * Author: silvest
 *
 * Created on November 30, 2010, 1:27 PM
 */

#ifndef STANDARDMODEL_H
#define	STANDARDMODEL_H

#include <gslpp.h>
#include "QCD.h"
#include "CKM.h"
#include "WilsonCoefficient.h"

using namespace gslpp;
/**
 * @class StandardModel
 * @brief Standard Model Class
 */
class StandardModel: public QCD {
public:
    enum lepton {NEUTRINO_1,ELECTRON,NEUTRINO_2,MU,NEUTRINO_3,TAU};
    static const int NSMvars = 17;
    static const std::string SMvars[NSMvars];

    /**
     * updates the SM parameters found in the argument
     * @param a Parameters object containing the parameters to be updated
     */
//    void update(Parameters&);

    /**
     * updates the SM parameters found in the argument
     * @param a map containing the parameters (all as double) to be updated
     */
    void Update(const std::map<std::string, double>&);

    bool Init(const std::map<std::string, double>&);
    
    void SetSMParameter(std::string, double);
    
    StandardModel();

    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * @return the VEV
     */
    double v() const;

    /**
     * @return the W boson mass at tree level
     */
    double Mw_tree() const;    
    
    /**
     * @return the W boson mass, including radiative corrections
     */
    virtual double Mw() const;    
    
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @return the CKM matrix
     */
    matrix<complex> getVCKM() const { return VCKM; }

    /**
     * @brief set the CKM matrix
     * @param VCKM the CKM matrix
     */
    void setVCKM(matrix<complex> VCKM) { this->VCKM = VCKM; }

    /**
     * @return the PMNS matrix
     */
    matrix<complex> getUPMNS() const { return UPMNS; }

    /**
     * @brief set the PMNS matrix
     * @param UPMNS the PMNS matrix
     */
    void setUPMNS(matrix<complex> UPMNS) { this->UPMNS = UPMNS; }

    /**
     *
     * @return up Yukawa matrix
     */
    matrix<complex> getYu() const {
        return Yu;
    }

    /**
     *
     * @return down Yukawa matrix
     */
    matrix<complex> getYd() const {
        return Yd;
    }

    /**
     *
     * @return neutrino Yukawa matrix
     */
    matrix<complex> getYn() const {
        return Yn;
    }

    /**
     *
     * @return charged lepton Yukawa matrix
     */
    matrix<complex> getYe() const {
        return Ye;
    }

    /**
     *
     * @return the Fermi constant
     */
    double getGF() const {
        return GF;
    }

    /**
     * @brief set the Fermi constant
     * @param GF the Fermi constant
     */
    void setGF(double GF) {
        this->GF = GF;
    }

//   /**
//     *
//     * @return @f$\alpha_s(M_Z)@f$
//     */
//    double getAlsMz() const {
//        return AlsMz;
//    }
//
//    /**
//     * set @f$\alpha_s(M_Z)@f$
//     * @param AlsMz @f$\alpha_s(M_Z)@f$
//     */
//    void setAlsMz(double AlsMz) {
//        this->AlsMz = AlsMz;
//    }

    /**
     *
     * @return the electromagnetic coupling
     */
    double getAle() const {
        return ale;
    }

    /**
     * @brief set the electromagnetic coupling
     * @param ale the electromagnetic coupling
     */
    void setale(double ale) {
        this->ale = ale;
    }

    /**
     *
     * @return @f$\Delta\alpha_\mathrm{had}^5(M_Z)@f$
     */
    double getDAle5Mz() const {
        return dAle5Mz;
    }

    /**
     * set @f$\Delta\alpha_\mathrm{had}^5(M_Z)@f$
     * @param dAle5Mz @f$\Delta\alpha_\mathrm{had}^5(M_Z)@f$
     */
    void setDAle5Mz(double dAle5Mz) {
        this->dAle5Mz = dAle5Mz;
    }

//    /**
//     *
//     * @return the Z boson mass
//     */
//    double getMz() const {
//        return Mz;
//    }
//
//    /**
//     * @brief set the Z boson mass
//     * @param Mz the Z boson mass
//     */
//    void setMz(double Mz) {
//        this->Mz = Mz;
//    }

    /**
     *
     * @return the Higgs mass
     */
    double getMHl() const {
        return mHl;
    }

    /**
     * @brief set the Higgs mass
     * @param mHl the Higgs mass
     */
    void setMHl(double mHl) {
        this->mHl = mHl;
    }

    virtual const double matchingScale() const ;

    ////////////////////////////////////////////////////////////////////////
    
    // Angles
    double getBeta() const;
    double getGamma() const;
    double getAlpha() const;
    double getBetas() const;

    // Lambda_q
    complex getlamt() const;
    complex getlamc() const;
    complex getlamu() const;

    complex getlamt_d() const;
    complex getlamc_d() const;
    complex getlamu_d() const;

    complex getlamt_s() const;
    complex getlamc_s() const;
    complex getlamu_s() const;

    // Sides
    double getRt() const;
    double getRts() const;
    double getRb() const;

    CKM getCKM() const {
        return myCKM;
    }
    
    ///////////////////////////////////////////////////////////////////////////

    Particle getLeptons(const int p) const {
        return leptons[p];
    }

    double getMuw() const {
        return muw;
    }

protected:
    matrix<complex> VCKM,UPMNS, Yu, Yd, Yn, Ye;
    //double AlsMz, Mz;
    double GF, ale, dAle5Mz, mHl, lambda, A, rhob, etab;
    double muw, mub, muc;
    CKM myCKM;
    Particle leptons[6];

private:
    bool computeCKM, computeYe, computeYn;
};

#endif	/* STANDARDMODEL_H */
