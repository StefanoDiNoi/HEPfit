#!/bin/bash
#
# Usage:
#   sh makePackage.sh
#

VERSION="0.2"

###########################################################
# Original source codes

ORGDIR="${HOME}/NetBeansProjects/SusyFit"

###########################################################
# List of Netbeans projects

PROJECTARRAY=()
#PROJECTARRAY+=( "Analysis" )
PROJECTARRAY+=( "ComputeObservables" )
#PROJECTARRAY+=( "EventGeneration" )
PROJECTARRAY+=( "EW" )
PROJECTARRAY+=( "Flavour" )
#PROJECTARRAY+=( "GeneralSUSY" )
PROJECTARRAY+=( "gslpp" )
PROJECTARRAY+=( "HiggsExtensions" )
PROJECTARRAY+=( "InputParser" )
#PROJECTARRAY+=( "LeptonFlavour" )
PROJECTARRAY+=( "LoopFunctions" )
#PROJECTARRAY+=( "MFV" )
PROJECTARRAY+=( "MonteCarlo" )
PROJECTARRAY+=( "NewPhysics" )
PROJECTARRAY+=( "Observables" )
#PROJECTARRAY+=( "pMSSM" )
PROJECTARRAY+=( "StandardModel" )
#PROJECTARRAY+=( "SUSY" )
#PROJECTARRAY+=( "SUSYMassInsertion" )
#PROJECTARRAY+=( "THDM" )
#PROJECTARRAY+=( "Utils" )
#PROJECTARRAY+=( "ZFitterWrapper" )

###########################################################
# input and output directories

CURRENTDIR=`pwd`
SCRIPTPATH=${0%/*}
if [ "$SCRIPTPATH" = "makePackage.sh" ]; then
    SCRIPTPATH="./"
fi
PYSCRIPT="${SCRIPTPATH}/genCMakeListsTxt.py"

# check the original directory
if [ ! -d "$ORGDIR" ]; then
    echo "$ORGDIR does not exist!"
    exit 1
fi

# output directory
OUTDIR="${CURRENTDIR}/SusyFit-${VERSION}"
if [ ! -d "$OUTDIR" ]; then
    echo "mkdir $OUTDIR"
    mkdir $OUTDIR
fi
if [ "$ORGDIR" = "$OUTDIR" ]; then
    echo "The target directory has to differ from the original directory!"
    exit 1
fi

if [ ! -d "${OUTDIR}/examples-src" ]; then
    echo "mkdir ${OUTDIR}/examples-src"
    mkdir ${OUTDIR}/examples-src
fi

###########################################################
# copy susyfit codes

for PROJECT in ${PROJECTARRAY[@]}
do
    if [ ! -d "${OUTDIR}/${PROJECT}" ]; then
        echo "midir ${OUTDIR}/${PROJECT}"
        mkdir ${OUTDIR}/${PROJECT}
    fi

    if [ "$PROJECT" = "Analysis" ]; then
        cp -af ${ORGDIR}/${PROJECT}/main.cpp ${OUTDIR}/${PROJECT}/
    else
        cp -af ${ORGDIR}/${PROJECT}/src ${OUTDIR}/${PROJECT}/
    fi
done

if [ ! -d "${OUTDIR}/doc" ]; then
    echo "mkdir ${OUTDIR}/doc"
    mkdir ${OUTDIR}/doc
fi
cp -af ${ORGDIR}/doc/COPYING ${OUTDIR}/doc/
cp -af ${ORGDIR}/doc/LICENSE ${OUTDIR}/doc/

###########################################################
# remove unnecessary files

rm -f ${OUTDIR}/StandardModel/src/EWSMTwoFermionsLEP2.h
rm -f ${OUTDIR}/StandardModel/src/EWSMTwoFermionsLEP2.cpp
rm -f ${OUTDIR}/StandardModel/src/EWSM_Output.h
rm -f ${OUTDIR}/StandardModel/src/EWSM_Output.cpp
rm -f ${OUTDIR}/EW/src/LEP2*

#FLAVORFILES="AmpDD2.cpp AmpDD2.h AmpDS1.cpp AmpDS1.h ArgD.h BR_Bdnunu.cpp BR_Bdnunu.h BR_Bsnunu.cpp BR_Bsnunu.h BR_Kmumu.cpp BR_Kmumu.h BR_Kp0nunu.cpp BR_Kp0nunu.h BR_Kppnunu.cpp BR_Kppnunu.h CPenguinBox.cpp CPenguinBox.h CPenguinBoxMu.cpp CPenguinBoxMu.h Charm_Kpnunu.cpp Charm_Kpnunu.h EpsilonP_O_Epsilon.cpp EpsilonP_O_Epsilon.h EvolDC1.cpp EvolDC1.h EvolDC1Buras.cpp EvolDC1Buras.h EvolDF1nlep.cpp EvolDF1nlep.h HeffDC1.cpp HeffDC1.h HeffDF1bnlep.cpp HeffDF1bnlep.h HeffDS1.cpp HeffDS1.h M12D.h"
#for FLAVOR in $FLAVORFILES
#do
#    rm -f ${OUTDIR}/Flavour/src/${FLAVOR}
#done

###########################################################
# generate CMakeLists.txt in each project

for PROJECT in ${PROJECTARRAY[@]}
do
    CONF="${ORGDIR}/${PROJECT}/nbproject/configurations.xml"
    if [ ! -e "$CONF" ]; then
        echo "$CONF does not exist!"
        exit 1
    fi

    echo "generating ${PROJECT}/CMakeLists.txt"
    python3 $PYSCRIPT $PROJECT $CONF > ${OUTDIR}/${PROJECT}/CMakeLists.txt
done

###########################################################
# copy other necessary files

SED_ARG="-e 's/VERSIONNUMBER/${VERSION}/g'"

eval sed "$SED_ARG" ${SCRIPTPATH}/etc/INSTALL > ${OUTDIR}/INSTALL
eval sed "$SED_ARG" ${SCRIPTPATH}/etc/README.md > ${OUTDIR}/README.md

cp ${SCRIPTPATH}/etc/CMakeLists.txt ${OUTDIR}/
cp ${SCRIPTPATH}/etc/SusyFit_noMCMC.h.in ${OUTDIR}/
cp ${SCRIPTPATH}/etc/BAT_make_wrapper.sh.in ${OUTDIR}/
cp ${SCRIPTPATH}/etc/cmake_uninstall.cmake.in ${OUTDIR}/
cp ${SCRIPTPATH}/etc/susyfit-config.in ${OUTDIR}/
eval sed "$SED_ARG" ${SCRIPTPATH}/etc/SusyFit.pc.in > ${OUTDIR}/SusyFit.pc.in
cp ${SCRIPTPATH}/etc/SusyFit.h.in ${OUTDIR}/
cp ${SCRIPTPATH}/etc/BAT_mpi_patch.txt ${OUTDIR}/

cp -r ${SCRIPTPATH}/etc/examples-src/LibMode_config ${OUTDIR}/examples-src/
cp -r ${SCRIPTPATH}/etc/examples-src/LibMode_header ${OUTDIR}/examples-src/
cp -r ${SCRIPTPATH}/etc/examples-src/MonteCarloMode ${OUTDIR}/examples-src/
cp -r ${SCRIPTPATH}/etc/examples-src/config ${OUTDIR}/examples-src/
cp -r ${SCRIPTPATH}/etc/examples-src/config/input ${OUTDIR}/examples-src/config/

###########################################################
# copy Doxygen files

DOXYGENDIR=${OUTDIR}/Doxygen
if [ ! -d "${DOXYGENDIR}" ]; then
    echo "mkdir ${DOXYGENDIR}"
    mkdir ${DOXYGENDIR}
fi
if [ ! -d "${DOXYGENDIR}/images" ]; then
    echo "mkdir ${DOXYGENDIR}/images"
    mkdir ${DOXYGENDIR}/images
fi
DOXYFILELIST="Doxyfile DoxygenLayout.xml customdoxygen.css footer.html header.html Installation.md MainPage.md Models.md Usage.md EW.bib QCD.bib Higgs.bib bibconversion.pl"
for DOXYFILE in $DOXYFILELIST
do
    cp -af ${ORGDIR}/Doxygen/${DOXYFILE} ${DOXYGENDIR}/
done
cp -af ${ORGDIR}/Doxygen/images/Model_inherit_graph.svg ${DOXYGENDIR}/images/

###########################################################
# Example main files

SED_ARG="-e 's/ComputeObservables.h/SusyFit.h/g'"
ORGFILE=${ORGDIR}/Analysis/main_libmode_config_example.cpp
eval sed "$SED_ARG" ${ORGFILE} > ${OUTDIR}/examples-src/LibMode_config/libmode_config.cpp
ORGFILE=${ORGDIR}/Analysis/main_libmode_header_example.cpp
eval sed "$SED_ARG" ${ORGFILE} > ${OUTDIR}/examples-src/LibMode_header/libmode_header.cpp
SED_ARG="-e 's/MonteCarlo.h/SusyFit.h/g'"
ORGFILE=${ORGDIR}/Analysis/main_MCMC_example.cpp
eval sed "$SED_ARG" ${ORGFILE} > ${OUTDIR}/examples-src/MonteCarloMode/MCMC.cpp

###########################################################
# Patch

sh ${SCRIPTPATH}/mod.sh ${OUTDIR}/InputParser/src/ModelFactory.cpp ${OUTDIR}/EW/src/EWObservables.h ${OUTDIR}/InputParser/src/ThObsFactory.cpp ${OUTDIR}/StandardModel/src/StandardModel.cpp ${OUTDIR}/StandardModel/src/StandardModel.h
echo "applying patches to souce codes..."

###########################################################
# Archive

echo "tar zcf SusyFit-${VERSION}.tar.gz SusyFit-${VERSION}"
tar zcf SusyFit-${VERSION}.tar.gz SusyFit-${VERSION}

###########################################################
