// Copyright 2019-20 Genten Studios
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


/**
 * @file Actor.hpp
 * @brief Header file for the Actor interface.
 *
 * @copyright Copyright (c) 2019-2020 Genten Studios
 */

#pragma once

#include <Common/Math/Math.hpp>

namespace phx
{
	class Actor
	{
	public:
		Actor();

		math::vec3 getPosition() const;
		bool       setPosition(math::vec3 pos);
		math::vec3 getRotation() const;
		bool       setRotation(math::vec3 rot);

		math::vec3 getDirection() const;

		/**
		 * @brief Gets the actor's current speed.
		 * @return The actor's current speed.
		 */
		int getMoveSpeed() const;

		/**
		 * @brief Sets the actors's current speed.
		 * @param speed The speed to set.
		 * @return true If the speed was able to be set.
		 * @return false If the speed was invalid, or unable to set.
		 */
		bool setMoveSpeed(int speed);

	private:
		math::vec3 m_rotation;
		math::vec3 m_position;
		int        m_moveSpeed;
	};
} // namespace phx


