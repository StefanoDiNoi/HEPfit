/* 
 * File:   ZFsigmaQuarksLEP2.h
 * Author: mishima
 */

#ifndef ZFSIGMAQUARKSLEP2_H
#define	ZFSIGMAQUARKSLEP2_H

#include <ThObservable.h>
#include "ZFitter.h"


class ZFsigmaQuarksLEP2 : public ThObservable {
public:

    /**
     * @brief ZFsigmaQuarksLEP2 constructor
     * @param[in] ZF_i an object of ZFitter class
     * @param[in] sqrt_s_i \sqrt{s} of the e+ e- pair in the initial state
     */
    ZFsigmaQuarksLEP2(const ZFitter& ZF_i, const double sqrt_s_i) : ThObservable(ZF_i), 
            myZF(ZF_i), sqrt_s(sqrt_s_i) {};

    /**
     * @return the hadronic cross section in pb at sqrt_s
     */
    double getThValue();

    
private:
    const ZFitter& myZF;
    const double sqrt_s;
};

#endif	/* ZFSIGMAQUARKSLEP2_H */
