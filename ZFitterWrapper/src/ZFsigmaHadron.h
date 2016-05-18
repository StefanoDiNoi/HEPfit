/* 
 * Copyright (C) 2012 HEPfit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef ZFSIGMAHADRON_H
#define	ZFSIGMAHADRON_H

#include <ThObservable.h>
#include "ZFitterWrapper.h"


class ZFsigmaHadron : public ThObservable {
public:

    /**
     * @brief ZFsigmaHadron constructor
     * @param[in] ZF_i an object of ZFitter class
     */
    ZFsigmaHadron(const StandardModel& SM_i) : ThObservable(SM_i), myZF(SM_i) {};

    /**
     * @return the hadronic cross section in nb
     */
    double computeThValue();

    
private:
    const ZFitterWrapper& myZF;
};

#endif	/* ZFSIGMAHADRON_H */

