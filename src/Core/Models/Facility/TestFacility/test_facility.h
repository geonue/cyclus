#if !defined _TESTFACILITY_H_
#define _TESTFACILITY_H_

#include "facility_model.h"
#include "material.h"

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/// This is the simplest possible Facility, for testing
class TestFacility: public cyclus::FacilityModel {
 public:
  TestFacility(cyclus::Context* ctx) : cyclus::FacilityModel(ctx) { };
  virtual cyclus::Model* clone() {return new TestFacility(context());};

  void ReceiveMessage(cyclus::Message::Ptr msg) {
    msg->SetDir(cyclus::DOWN_MSG);
  }

  void ReceiveMaterial(cyclus::Transaction trans,
                       std::vector<cyclus::Material::Ptr> manifest) { }

  void CloneModuleMembersFrom(cyclus::FacilityModel* source) { }
  void HandleTick(int time) { };
  void HandleTock(int time) { };
};

#endif
