// $Id: ESMCI_Grid.h,v 1.9 2007/07/20 00:27:28 oehmke Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2007, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.

// ESMCI Grid include file for C++

// (all lines below between the !BOP and !EOP markers will be included in
//  the automated document processing.)
//-------------------------------------------------------------------------
// these lines prevent this file from being read more than once if it
// ends up being included multiple times

#ifndef ESMCI_Grid_H
#define ESMCI_Grid_H

//-------------------------------------------------------------------------
//BOP
// !CLASS: ESMCI_Grid - Grid
//
// !DESCRIPTION:
//
// The code in this file defines the C++ {\tt Grid} members and method
// signatures (prototypes).  The companion file {\tt ESMC\_Grid.C}
// contains the full code (bodies) for the {\tt Grid} methods.
//
///EOP
//-------------------------------------------------------------------------


#include "ESMC_Base.h"
#include "ESMC_DistGrid.h"
#include "ESMC_Array.h"


// Eventually move this to ESMCI_Util.h
enum ESMC_GridStatus {ESMC_GRIDSTATUS_NOT_READY=1,
		      ESMC_GRIDSTATUS_SHAPE_READY
};

// Eventually move this to ESMCI_Util.h
//enum ESMC_CopyFlag {ESMC_DATA_REF=1,
//		    ESMC_DATA_COPY
//};

// Start name space
namespace ESMCI {  

class Grid;
class ProtoGrid;

// class definition
class Grid : public ESMC_Base {    // inherits from ESMC_Base class
  private:

  // holder for set/commit data
  ProtoGrid *proto;

  // Grid Status
  ESMC_GridStatus status;

  // global information
  ESMC_TypeKind typekind;
  
  int distRank;
  int *dimmap;    // size of dimmap = distRank, entries are 0-based

  int undistRank;
  int *lbounds; // size of lbounds = undistRank
  int *ubounds; // size of ubounds = undistRank
  
  int rank;
  // User info about coord ranks and dimmap
  int *coordRank; // size of coordRank = rank
  int **coordDimMap; // size of coordDimMap = rankxrank  [coord][dim of coord array], 0-based

  int staggerLocCount;
  Array ***coordArrayList; // size of coordArrayList = staggerLocCountxrank [staggerLoc][coord]
  int   **coordAlignList;     // hold alignment info [staggerloc][coord][dim]
  int   **coordLWidthList;     // hold LWidth info [staggerloc][dim]
  int   **coordUWidthList;     // hold UWidth info [staggerloc][dim]
  bool  **didIAllocList;        // if true, I allocated this Array [staggerloc][coord]

  // map grid dim to distgrid dim and grid bounds dim
  bool *gridIsDist;  // size=rank [grid-dim]
  int *gridMapDim;   // size=rank [grid-dim]

  // map coord dim to distgrid dim and coord array bounds dim
  bool **coordIsDist; // size=rankxrank [coord][coord-dim]
  int **coordMapDim; // size=rankxrank [coord][coord-dim]

  
  // size of localDE each bit says if that dimension is on a boundary
  char *isDELBnd;
  char *isDEUBnd;

  int gridType;
  ESMC_IndexFlag indexflag;
  DistGrid *distgrid;
  
 public:

  // accessor methods
  const ESMC_GridStatus getStatus(void) const {return status;}
  ProtoGrid *getProtoGrid(void) {return proto;}
  const int getRank(void) const {return rank;}
  const int getDistRank(void) const {return distRank;}
  const int getUndistRank(void) const {return undistRank;}
  const int getTileCount(void) const {return distgrid->getPatchCount();}
  const int getStaggerLocCount(void) const {return staggerLocCount;}
  const int getGridType(void) const {return gridType;}
  const ESMC_IndexFlag getIndexFlag(void) const {return indexflag;}
  const ESMC_TypeKind getTypeKind(void) const {return typekind;}
  const DistGrid *getDistGrid(void) const {return distgrid;}
  const int *getDimMap(void) const {return dimmap;}
  const int *getLbounds(void) const {return lbounds;}
  const int *getUbounds(void) const {return ubounds;}
  const int *getCoordRank(void) const {return coordRank;}
        int **getCoordDimMap(void) const {return coordDimMap;}
  const char *getName(void)  const {return ESMC_BaseGetName();}
        bool *getGridIsDist(void) const {return gridIsDist;} 
        int  *getGridMapDim(void) const {return gridMapDim;} 
        bool **getCoordIsDist(void) const {return coordIsDist;} 
        int  **getCoordMapDim(void) const {return coordMapDim;} 


  // Set Grid default values
  friend void  _GridSetDefaults(Grid *grid);

  
  // external methods:  
  
  // Grid Construct (grid NOT usable after construction)
  Grid();

  // make grid usable
  int activate(
       char *name,                            // (in)
       ESMC_TypeKind typekindArg,              // (in)
       DistGrid *distgridArg,                  // (in)
       int distRankArg,                        // (in)
       int *dimmapArg,                         // (in)
       int undistRankArg,                      // (in)
       int *lboundsArg,                        // (in)
       int *uboundsArg,                        // (in)
       int rankArg,                            // (in)
       int *coordRankArg,                     // (in)
       int **coordDimMapArg,                   // (in)
       ESMC_IndexFlag indexflagArg,             // (in)
       int gridTypeArg                          // (in)
       );
  
  // Grid Destruct
  ~Grid();


  int setCoordArray(
		    int _staggerloc, // (in)
		    int _coord,      // (in)
		    Array *_array,   // (in)
		    bool _self_alloc // (in)
		    );

  int setCoordInfo(
		    int _staggerloc, // (in)
		    int *coordAlign,  // (in)
		    int *coordLWidth,  // (in)
		    int *coordUWidth  // (in)
		    );


  int getCoordArray(
		    int _staggerloc, // (in)
		    int _coord,      // (in)
		    Array **_array   // (in)
		    );
  

int getStaggerUWidth(
		     int _staggerloc,
		     int _localDE, 
		     int *_UWidth // needs to be of the same size as the grid rank
		     );

int getStaggerLWidth(
		     int _staggerloc,
		     int _localDE, 
		     int *_LWidth // needs to be of the same size as the grid rank
		     );

int getCoordExclusiveUBnd(
  int _staggerloc, // (in)
  int _coord,      // (in)
  int _localDE,    // (in)
  int *_bnd        // (out)
  );

 int addProtoGrid();

  
};  // end class ESMC_Grid


 int GridCommit(
		Grid *_grid
		);
 
 
 Grid *GridCreate(
		  int nameLen,                                // (in)
		  char *name,                                 // (in)
		  ESMC_TypeKind *typekind,                    // (in)
		  DistGrid *distgrid,                  // (in)
		  InterfaceInt *dimmap,                  // (in)
		  InterfaceInt *lbounds,                 // (in)
		  InterfaceInt *ubounds,                 // (in)
		  InterfaceInt *coordRank,              // (in)
		  InterfaceInt *coordDimMap,             // (in)
		  ESMC_IndexFlag *indexflag,                  // (in)
		  int *gridType,                              // (in)
		  int *rc                                     // (out) return code
		  );


int GridSetFromDistGrid(
  Grid *_grid,
  int _nameLen,                                // (in)
  char *_name,                                 // (in)
  ESMC_TypeKind *_typekind,                    // (in)
  DistGrid *_distgrid,                    // (in)
  InterfaceInt *_dimmap,                  // (in)
  InterfaceInt *_lbounds,                 // (in)
  InterfaceInt *_ubounds,                 // (in)
  InterfaceInt *_coordRank,              // (in)
  InterfaceInt *_coordDimMap,             // (in)
  ESMC_IndexFlag *_indexflag,                  // (in)
  int *_gridType                             // (in)
  );
 
Grid *GridCreateEmpty(int *_rc);


int gridAllocCoord(
		   Grid *_grid, 
		   int *_staggerloc,
		   InterfaceInt *_coordLWidthArg,
		   InterfaceInt *_coordUWidthArg,
		   InterfaceInt *_coordAlign
		   );

int gridSetCoordFromArray(
  Grid *_grid, 
  int *_staggerloc,
  int *_coord,
  Array *_array,
  ESMC_DataCopy *_docopy
  );


 int gridGetCoordIntoArray(			  
			   Grid *_grid, 
			   int *_staggerloc,
			   int *_coord,
			   Array **_array,
			   ESMC_DataCopy *_docopy
			   );
 
 int GridDestroy(Grid **grid);

 // Class for holding data set after grid empty creation, but before grid is finally created.
class ProtoGrid { 
 public:
  int nameLen; 
  char *name;  
  ESMC_TypeKind *typekind;
  DistGrid *distgrid;     
  InterfaceInt *dimmap;   
  InterfaceInt *lbounds;  
  InterfaceInt *ubounds;  
  InterfaceInt *coordRank;  
  InterfaceInt *coordDimMap; 
  ESMC_IndexFlag *indexflag; 
  int *gridType;    

  // Proto Grid Construct
  ProtoGrid();

  // Proto Grid Destruct
  ~ProtoGrid();
         
}; // end class ProtoGrid

 
} // END ESMCI namespace

#endif  // ESMC_GridI_H

