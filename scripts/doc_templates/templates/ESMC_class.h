// $Id: ESMC_class.h,v 1.8 2002/10/14 21:53:58 cdeluca Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2003, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the GPL.

// ESMF <Class> C++ definition include file
//
// (all lines below between the !BOP and !EOP markers will be included in 
//  the automated document processing.)
//-------------------------------------------------------------------------
//
 // these lines prevent this file from being read more than once if it
 // ends up being included multiple times

 #ifndef ESMC_<Class>_H
 #define ESMC_<Class>_H

//-------------------------------------------------------------------------

 // Put any constants or macros which apply to the whole component in this file.
 // Anything public or esmf-wide should be up higher at the top level
 // include files.
 #include <ESMC_<Comp>.h> 

//-------------------------------------------------------------------------
//BOP
// !CLASS:  ESMC_<Class> - one line general statement about this class
//
// !DESCRIPTION:
//
// The code in this file defines the C++ <Class> members and declares method 
// signatures (prototypes).  The companion file ESMC_<Class>.C contains
// the definitions (full code bodies) for the <Class> methods.
//
// < insert a paragraph or two explaining what you'll find in this file >
//
//-------------------------------------------------------------------------
// 
// !USES:
 #include <ESMC_Base.h>  // all classes inherit from the ESMC Base class.
 //#include <ESMC_XXX.h>   // other dependent classes (subclasses, aggregates,
                        // composites, associates, friends)

// !PUBLIC TYPES:
 class ESMC_<Class>Config;
 class ESMC_<Class>;

// !PRIVATE TYPES:

 // class configuration type
 class ESMC_<Class>Config {
   private:
 //   < insert resource items here >
 };

 // class definition type
 class ESMC_<Class> : public ESMC_Base {    // inherits from ESMC_Base class

   private:
 //  < insert class members here >  corresponds to type ESMF_<Class> members
 //                                 in F90 modules

// !PUBLIC MEMBER FUNCTIONS:
//
// pick one or the other of the init/create sections depending on
//  whether this is a deep class (the class/derived type has pointers to
//  other memory which must be allocated/deallocated) or a shallow class
//  (the class/derived type is self-contained) and needs no destroy methods
//  other than deleting the memory for the object/derived type itself.

  public:
 // the following methods apply to deep classes only
    ESMC_<Class> *ESMC_<Class>Create(args, int rc);// interface only, deep class
    int ESMC_<Class>Destroy(void);            // interface only, deep class
    int ESMC_<Class>Construct(args);          // internal only, deep class
    int ESMC_<Class>Destruct(void);           // internal only, deep class

 // or
 // the following method applies to a shallow class
    int ESMC_<Class>Init(args);         // shallow class only

 // optional configuration methods
    int ESMC_<Class>GetConfig(ESMC_<Class>Config *config) const;
    int ESMC_<Class>SetConfig(const ESMC_<Class>Config *config);

 // accessor methods for class members
    int ESMC_<Class>Get<Value>(<value type> *value) const;
    int ESMC_<Class>Set<Value>(<value type>  value);
    
 // required methods inherited and overridden from the ESMC_Base class
    int ESMC_<Class>Validate(const char *options) const;
    int ESMC_<Class>Print(const char *options) const;

 // native C++ constructors/destructors
	ESMC_<Class>(args);
	~ESMC_<Class>(args);
  
 // < list the rest of the public interface methods here >
  
// !PRIVATE MEMBER FUNCTIONS:
//
  private: 
//
 // < declare private interface methods here >
//
//EOP
//-------------------------------------------------------------------------

 };   // end class ESMC_<Class>

 #endif  // ESMC_<Class>_H
