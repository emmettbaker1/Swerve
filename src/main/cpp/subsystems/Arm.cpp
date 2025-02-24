// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Arm.h"
#include "Constants.h"

using namespace ArmConstants;

/*
Todo: will need to update the type of motor used on the intake once it's known
Todo: Will need to make methods that make sense for what the intake will do
- the intake is planned to be a conveyor so will need to turn one direction at a specific speed
- I'm thinking it should be able to be reversed if we need to 
-it'd be nice to know if we have a note loaded 
*/
Arm::Arm() {
  // Implementation of subsystem constructor goes here.
  //frc::PWMSparkMax m_conveyorMotor(kconveyorMotorPort);
  
}

frc2::CommandPtr Arm::RunArm() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([ this ] { 
    m_armMotor.Set(kArmSpeed);
    frc::SmartDashboard::PutString("Arm","Forward"); 
    });
  //RunOnce creates a command that calls a lambda once, and then finishes.
}

frc2::CommandPtr Arm::ReverseArm() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([ this ] { 
    m_armMotor.Set(-kArmSpeed);
    frc::SmartDashboard::PutString("Arm","Reverse"); 
    });
}

frc2::CommandPtr Arm::Stop(){
return RunOnce([ this ] { 
  m_armMotor.Set(0);
    });
}

bool isArmUp() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void Arm::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Arm::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
