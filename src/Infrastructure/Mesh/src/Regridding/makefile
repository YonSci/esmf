# $Id$

# leave alone.
ALL: build_here 

# Workaround an MPICH2 issue
ESMF_CXXCOMPILECPPFLAGS += -DMPICH_IGNORE_CXX_SEEK

SOURCEC	  = \
            ESMCI_Conserve2ndInterp.C \
            ESMCI_ConserveInterp.C \
            ESMCI_ExtrapolationPoleLGC.C \
            ESMCI_Integrate.C \
            ESMCI_Interp.C \
            ESMCI_Mapping.C \
            ESMCI_CreepFill.C \
            ESMCI_Extrap.C \
            ESMCI_MeshRegrid.C \
            ESMCI_PatchRecovery.C \
            ESMCI_Regrid_Helper.C \
            ESMCI_Search.C \
            ESMCI_SearchNearestDToSLGC.C \
            ESMCI_SearchNearestLGC.C \
            ESMCI_SearchNearestNPntsLGC.C \
            ESMCI_ShapeFunc.C \
            ESMCI_SpaceDir.C \
            ESMCI_WMat.C \

OBJSC     = $(addsuffix .o, $(basename $(SOURCEC)))
OBJSF     = $(addsuffix .o, $(basename $(SOURCEF)))

LIBBASE	  = libesmf
LOCDIR	  = src/Infrastructure/Mesh/src/Regridding

CLEANDIRS   =
CLEANFILES  = 
CLOBBERDIRS =

include ${ESMF_DIR}/makefile

ifeq ($(ESMF_MOAB),internal)
ESMF_CXXCOMPILECPPFLAGS += -I$(ESMF_DIR)/$(LOCDIR)/../Moab \
                           -I$(ESMF_DIR)/$(LOCDIR)/../Moab/parallel \
                           -I$(ESMF_DIR)/$(LOCDIR)/../Moab/LocalDiscretization
endif
