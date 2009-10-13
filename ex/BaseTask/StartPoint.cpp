/* Generated by Together */

#include "StartPoint.hpp"
#include <assert.h>

bool 
StartPoint::transition_exit(const AIRCRAFT_STATE & ref_now, 
                                  const AIRCRAFT_STATE & ref_last)
{
  // consider entry of start zone to be same as exit point
  bool exited = OrderedTaskPoint::transition_exit(ref_now, ref_last);
  if (exited) {
    clear_sample_all_but_last(ref_last);
    state_entered = ref_last;
  }
  return exited;
}


double
StartPoint::getElevation()
{
  // no need for safety height at start?
  return Elevation;
}


void 
StartPoint::set_leg_in(TaskLeg* the_leg) 
{
  assert(the_leg == NULL);
  // should not ever have an inbound leg
}
