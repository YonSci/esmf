// $Id: ESMC_Xform.h,v 1.2 2003/01/23 21:05:50 nscollins Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2003, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the GPL.

// ESMF Xform C++ declaration include file
//
// (all lines below between the !BOP and !EOP markers will be included in 
//  the automated document processing.)
//-----------------------------------------------------------------------------
//
 // these lines prevent this file from being read more than once if it
 // ends up being included multiple times

 #ifndef ESMC_Xform_H
 #define ESMC_Xform_H

//-----------------------------------------------------------------------------

 // Put any constants or macros which apply to the whole component in this file.
 // Anything public or esmf-wide should be up higher at the top level
 // include files.
 #include <ESMC_Comp.h> 

//-----------------------------------------------------------------------------
//BOP
// !CLASS:  ESMC_Xform - one line general statement about this class
//
// !DESCRIPTION:
//
// The code in this file defines the C++ Xform members and declares method 
// signatures (prototypes).  The companion file ESMC_Xform.C contains
// the definitions (full code bodies) for the Xform methods.
//
// < insert a paragraph or two explaining what you'll find in this file >
//
//-----------------------------------------------------------------------------
// 
// !USES:
 #include <ESMC_Base.h>  // all classes inherit from the ESMC Base class.
 //#include <ESMC_XXX.h>   // other dependent classes (subclasses, aggregates,
                        // composites, associates, friends)

// !PUBLIC TYPES:
 class ESMC_XformConfig;
 class ESMC_Xform;
 class ESMC_State;

// !PRIVATE TYPES:

 // class configuration type
 class ESMC_XformConfig {
   private:
 //   < insert resource items here >
 };

 // class declaration type
 class ESMC_Xform : public ESMC_Base {    // inherits from ESMC_Base class

   private:
   // class data here

// !PUBLIC MEMBER FUNCTIONS:
//

  public:
    int ESMC_XformInit(void);
    int ESMC_XformApply(ESMC_State *state);

 // optional configuration methods
    int ESMC_XformGetConfig(ESMC_XformConfig *config) const;
    int ESMC_XformSetConfig(const ESMC_XformConfig *config);

 // accessor methods for class members
    //int ESMC_XformGet<Value>(<value type> *value) const;
    //int ESMC_XformSet<Value>(<value type>  value);
    
 // required methods inherited and overridden from the ESMC_Base class
    int ESMC_XformValidate(const char *options) const;
    int ESMC_XformPrint(const char *options) const;

 // secondary construct/destruct methods
    int ESMC_XformConstruct(void);
    int ESMC_XformDestruct(void);

 // native C++ constructors/destructors
	ESMC_Xform(void);
	~ESMC_Xform(void);
  
 // < declare the rest of the public interface methods here >
  
// !PRIVATE MEMBER FUNCTIONS:
//
  private: 
//
 // < declare private interface methods here >
//
//EOP
//-----------------------------------------------------------------------------

 };   // end class ESMC_Xform

// Create and Destroy are declared as class helper functions (not methods)
// since they create and destroy an ESMC_Xform object itself. E.g. if Create
// were a method, the ESMC_Xform object on whose behalf it was being invoked
// would need to already exist!  These functions are supersets of C++ new
// and delete; they perform allocation/deallocation specialized to
// an ESMC_Xform object.

 ESMC_Xform *ESMC_XformCreate(int *rc);// interface only, deep class
 int ESMC_XformDestroy(ESMC_Xform *xform); // interface only, deep class

 #endif  // ESMC_Xform_H
