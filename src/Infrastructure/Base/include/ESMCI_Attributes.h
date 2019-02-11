// $Id$
//
// Earth System Modeling Framework
// Copyright 2002-2018, University Corporation for Atmospheric Research,
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics
// Laboratory, University of Michigan, National Centers for Environmental
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory,
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.
//
// ESMF Attributes C++ include file
//
//-----------------------------------------------------------------------------
//

#ifndef ESMCI_ATTRIBUTES_H
#define ESMCI_ATTRIBUTES_H

//-----------------------------------------------------------------------------

#include <vector>
#include <fstream>

#include "ESMCI_Util.h"
#include "json.hpp"

using json = nlohmann::json;  // Convenience rename for JSON namespace.
using std::string;

//tdk:LAST: remove all tdk stuff (search for tdk)

// Standard ESMF check error macros
#define ESMF_CHECKERR_STD(name_rc, actual_rc, msg, update_rc) {if (actual_rc != ESMF_SUCCESS) {esmf_attrs_error local_macro_error(name_rc, actual_rc, msg); if (ESMC_LogDefault.MsgFoundError(actual_rc, local_macro_error.what(), ESMC_CONTEXT, &update_rc)) throw(local_macro_error);}}

#define ESMF_THROW_JSON(json_exc, name_rc, actual_rc, update_rc) {ESMC_LogDefault.MsgFoundError(actual_rc, json_exc.what(), ESMC_CONTEXT, &update_rc); throw(esmf_attrs_error(name_rc, actual_rc, json_exc.what()));}

#define ESMF_CATCH_PASSTHRU(exc_esmf) {ESMC_LogDefault.MsgFoundError(exc_esmf.getReturnCode(), exc_esmf.what(), ESMC_CONTEXT, nullptr); throw(exc_esmf);}

//-----------------------------------------------------------------------------
//BOP
// !CLASS:  Attributes
//
// !DESCRIPTION:
// The code in this file implements the Attributes defined type
// and methods.
//
//-----------------------------------------------------------------------------
//
// !USES:

namespace ESMCI {

enum ESMC_ISOCType {C_INT, C_LONG, C_FLOAT, C_DOUBLE, C_CHAR};

//-----------------------------------------------------------------------------

class esmf_attrs_error : public std::exception
{
public:
  esmf_attrs_error(const string &code_name, int rc, const string &msg);

  int getReturnCode() {return this->rc;}

  const char* what() const noexcept {return this->msg.c_str();}

private:
  string msg;
  int rc;
};

//-----------------------------------------------------------------------------

class Attributes {

protected:
  json storage;  // JSON object store for keys/values managed by this instance

  static json::json_pointer formatKey(const string& key, int& rc);
  virtual void init(void) {this->storage = json::object();}

public:
  Attributes(void) {this->init();}
//  Attributes(void) = default;  // Default constructor
  virtual ~Attributes(void) = default; // Default destructor
  Attributes(Attributes&&) = delete; // Move constructor
  Attributes(const Attributes&) = delete; // Copy constructor
  Attributes&operator=(const Attributes&) = delete; // Copy assignment
  Attributes&operator=(Attributes&&) = delete; // Move assignment

  Attributes(const json& storage);
  Attributes(json&& storage);
  Attributes(const string& input, int& rc);

  string dump(int& rc) const;
  string dump(int indent, int& rc) const;

  void erase(const string& key, const string& keyChild, int& rc);

  template <typename T>
  T get(const string& key, int& rc, T* def = nullptr) const;

  void get_isoc(ESMCI::ESMC_ISOCType ictype, void *ret, char* key, int& rc,
    void* def = nullptr) const;

  const json& getStorageRef(void) const;

  json& getStorageRefWritable(void);

  template <typename T, typename JT>
  T getPointer(const string& key, int& rc) const;

  bool hasKey(const string& key, int& rc, bool isptr = false) const;

  void parse(const string& input, int& rc);

  void deserialize(char *buffer, int *offset, int& rc);

  void serialize(char *buffer, int *length, int *offset,
    ESMC_InquireFlag inquireflag, int& rc);

  template <typename T>
  void set(const string& key, T value, bool force, int& rc);

  template <typename T>
  void set(const string& key, T values[], int& count, bool force, int& rc);

  void update(const Attributes& attrs, int& rc);

};

//-----------------------------------------------------------------------------

class PackageFactory
// tdk: FEATURE: add rule of five
{
private:
  json cache = json::object();
  json uris = json::object();

public:
  PackageFactory(void) = default;  // Default constructor
  ~PackageFactory(void) = default; // Default destructor

  json getOrCreateJSON(const string& key, int& rc, const string& uri = "");
};

//-----------------------------------------------------------------------------

void alignOffset(int &offset);
void broadcastAttributes(ESMCI::Attributes* attrs, int rootPet, int& rc); // tdk: FEATURE: non-blocking
bool isIn(const string& target, const std::vector<string>& container);
bool isIn(const std::vector<string>& target, const std::vector<string>& container);
bool isIn(const string& target, const json& j);

//-----------------------------------------------------------------------------

} // namespace

#endif  // ifdef barrier