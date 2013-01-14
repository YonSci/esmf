#ifdef ESMC_RCS_HEADER
"$Id: ESMC_Conf.h,v 1.20 2012/01/06 20:14:44 svasquez Exp $"
"Defines the configuration for this machine"
#endif

#if 0
Earth System Modeling Framework
Copyright 2002-2013, University Corporation for Atmospheric Research,
Massachusetts Institute of Technology, Geophysical Fluid Dynamics
Laboratory, University of Michigan, National Centers for Environmental
Prediction, Los Alamos National Laboratory, Argonne National Laboratory,
NASA Goddard Space Flight Center.
Licensed under the University of Illinois-NCSA License.
#endif

#if !defined(INCLUDED_CONF_H)
#define INCLUDED_CONF_H

#define PARCH_linux

#define FTN_X(func) func##_
#define FTNX(func) func##_

#if defined (__cplusplus)
// Typedef to match the data type of the 'hidden' string length
// argument that Fortran uses when passing CHARACTER strings.
typedef int ESMCI_FortranStrLenArg;
#endif

#define ESMC_PRESENT(arg) ( (arg) != 0 )

#ifdef S32
#define ESMC_POINTER_SIZE 4
#endif
#ifdef S64
#define ESMC_POINTER_SIZE 8
#endif

#endif
