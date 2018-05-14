# $Id$ 

ALL:  build_unit_tests
run:  
run_uni: run_unit_tests_uni

LOCDIR	  = src/Superstructure/Mapper/tests

.NOTPARALLEL:
TESTS_BUILD   =	$(ESMF_TESTDIR)/ESMCI_PolyUTest \
                $(ESMF_TESTDIR)/ESMCI_TwoVPolyUTest \
                $(ESMF_TESTDIR)/ESMCI_MatUTest \
                $(ESMF_TESTDIR)/ESMCI_PolyFitUTest \
                $(ESMF_TESTDIR)/ESMCI_SolverUTest \
                $(ESMF_TESTDIR)/ESMCI_LoadBalancerUTest

TESTS_RUN     =

TESTS_RUN_UNI =	RUN_ESMCI_PolyUTestUNI \
                RUN_ESMCI_TwoVPolyUTestUNI \
                RUN_ESMCI_MatUTestUNI \
                RUN_ESMCI_PolyFitUTestUNI \
                RUN_ESMCI_SolverUTestUNI \
                RUN_ESMCI_LoadBalancerUTestUNI


include $(ESMF_DIR)/makefile

CLEANDIRS   = 
CLEANFILES  = $(TESTS_BUILD)
CLOBBERDIRS =

DIRS        = 

ESMF_CXXCOMPILEOPTS += -std=c++11 -I/home/jayeshkrishna/parvis/lapack-3.4.2 -I/home/jayeshkrishna/parvis/lapack-3.4.2/lapacke/include -I/home/jayeshkrishna/parvis/CBLAS/include

ESMF_CXXLINKLIBS += -L/home/jayeshkrishna/parvis/lapack-3.4.2 -llapacke -llapack /home/jayeshkrishna/parvis/CBLAS/lib/cblas_LINUX.a -L/home/jayeshkrishna/parvis/BLAS -lblas_LINUX 

#       
#       
# Univariate Polynomial test
#

RUN_ESMCI_PolyUTestUNI:
	$(MAKE) TNAME=UniVPoly NP=1 ctest

RUN_ESMCI_TwoVPolyUTestUNI:
	$(MAKE) TNAME=TwoVPoly NP=1 ctest

RUN_ESMCI_MatUTestUNI:
	$(MAKE) TNAME=Matrix NP=1 ctest

RUN_ESMCI_PolyFitUTestUNI:
	$(MAKE) TNAME=FitPoly NP=1 ctest

RUN_ESMCI_SolverUTestUNI:
	$(MAKE) TNAME=Solver NP=1 ctest

RUN_ESMCI_LoadBalancerUTestUNI:
	$(MAKE) TNAME=LoadBalancer NP=1 ctest
