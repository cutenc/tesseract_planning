/**
 * @file simple_planner_interpolation_move_profile.h
 * @brief
 *
 * @author Matthew Powelson
 * @date July 23, 2020
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2020, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TESSERACT_MOTION_PLANNERS_SIMPLE_FIXED_SIZE_MOVE_PROFILE_H
#define TESSERACT_MOTION_PLANNERS_SIMPLE_FIXED_SIZE_MOVE_PROFILE_H

#include <tesseract_motion_planners/simple/profile/simple_planner_profile.h>

namespace tesseract_planning
{
class SimplePlannerFixedSizeMoveProfile : public SimplePlannerMoveProfile
{
public:
  using Ptr = std::shared_ptr<SimplePlannerFixedSizeMoveProfile>;
  using ConstPtr = std::shared_ptr<const SimplePlannerFixedSizeMoveProfile>;

  /**
   * @brief SimplePlannerFixedSizeMoveProfile
   * @param freespace_steps The number of steps to use for freespace instruction
   * @param linear_steps The number of steps to use for linear instruction
   */
  SimplePlannerFixedSizeMoveProfile(int freespace_steps = 10, int linear_steps = 10);

  std::vector<MoveInstructionPoly> generate(const MoveInstructionPoly& prev_instruction,
                                            const MoveInstructionPoly& prev_seed,
                                            const MoveInstructionPoly& base_instruction,
                                            const InstructionPoly& next_instruction,
                                            const std::shared_ptr<const tesseract_environment::Environment>& env,
                                            const tesseract_common::ManipulatorInfo& global_manip_info) const override;

  /** @brief The number of steps to use for freespace instruction */
  int freespace_steps;

  /** @brief The number of steps to use for linear instruction */
  int linear_steps;

protected:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive&, const unsigned int);  // NOLINT
};

}  // namespace tesseract_planning

BOOST_CLASS_EXPORT_KEY(tesseract_planning::SimplePlannerFixedSizeMoveProfile)

#endif  // TESSERACT_MOTION_PLANNERS_SIMPLE_FIXED_SIZE_MOVE_PROFILE_H
