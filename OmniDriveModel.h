#include "rec/robotino/api2/utils.h"
#include <cmath>

			/**
			* @brief	Project single motor speeds to velocity vector and vice versa.
			* 
			*/
			class OmniDriveModel
			{
			public:
				OmniDriveModel()
					: _rb( 0.132 )
					, _rw( 0.040 )
					, _gear( 16.0 )
				{
				}

				/**
				 * Sets the distance from robot center to wheel center.
				 * @param rb Distance from robot center to wheel center in m.
				 */
				void setRb( double rb ) { _rb = rb; }

				/**
				 * Sets the radius of the wheels.
				 * @param rw Radius of the wheels in m.
				 */
				void setRw( double rw ) { _rw = rw; }

				/**
				 * Sets the gear.
				 * @param gear Gear
				 */
				void setGear( double gear ) { _gear = gear; }

				/** @return Distance from robot center to wheel center in m. */
				double rb() const { return _rb; }

				/** @return Radius of the wheels in m. */
				double rw() const { return _rw; }

				/** @return gear. */
				double gear() const { return _gear; }

				/**
				* Project the velocity of the robot in cartesian coordinates to single motor speeds.
				*
				* @param m1		The resulting speed of motor 1 in rpm
				* @param m2		The resulting speed of motor 2 in rpm
				* @param m3		The resulting speed of motor 3 in rpm
				* @param vx		Velocity in x-direction in m/s
				* @param vy		Velocity in y-direction in m/s
				* @param omega	Angular velocity in rad/s
				* @throws		RobotinoException if no valid drive layout parameters are available.
				* @remark This function is thread save
				*/
				void project( float* m1, float* m2, float* m3, float vx, float vy, float omega ) const
				{
					//Projection matrix
					static const double v0[2] = { -0.5 * sqrt( 3.0 ),  0.5 };
					static const double v1[2] = {  0.0              , -1.0 };
					static const double v2[2] = {  0.5 * sqrt( 3.0 ),  0.5 };

					//Scale omega with the radius of the robot
					double vOmegaScaled = _rb * (double)omega ;

					//Convert from m/s to RPM
					const double k = 60.0 * _gear / ( 2.0 * rec::robotino::api2::PI * _rw );

					//Compute the desired velocity
					*m1 = static_cast<float>( ( v0[0] * (double)vx + v0[1] * (double)vy + vOmegaScaled ) * k );
					*m2 = static_cast<float>( ( v1[0] * (double)vx + v1[1] * (double)vy + vOmegaScaled ) * k );
					*m3 = static_cast<float>( ( v2[0] * (double)vx + v2[1] * (double)vy + vOmegaScaled ) * k );
				}

				/**
				* Project single motor speeds to velocity in cartesian coordinates.
				*
				* @param vx		The resulting speed in x-direction in m/s
				* @param vy		The resulting speed in y-direction in m/s
				* @param omega	The resulting angular velocity in rad/s
				* @param m1		Speed of motor 1 in rpm
				* @param m2		Speed of motor 2 in rpm
				* @param m3		Speed of motor 3 in rpm
				* @throws		RobotinoException if no valid drive layout parameters are available.
				* @remark This function is thread save
				*/
				void unproject( float* vx, float* vy, float* omega, float m1, float m2, float m3 ) const
				{
					//Convert from RPM to mm/s
					const double k = 60.0 * _gear / ( 2.0 * rec::robotino::api2::PI * _rw );

					*vx = static_cast<float>( ( (double)m3 - (double)m1 ) / sqrt( 3.0 ) / k );
					*vy = static_cast<float>( 2.0 / 3.0 * ( (double)m1 + 0.5 * ( (double)m3 - (double)m1 ) - (double)m2 ) / k );

					double vw = (double)*vy + (double)m2 / k;

					*omega = static_cast<float>( vw / _rb );
				}

			private:
				/**
				* Distance from robot center to wheel center in m.
				*/
				double _rb;

				/**
				* Radius of the wheels in m.
				*/
				double _rw;

				/**
				* Gear between motor and wheel.
				*/
				double _gear;
			};
