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
 * @file Player.hpp
 * @brief Header file for the Player derivation of Actor.
 *
 * @copyright Copyright (c) 2019-2020 Genten Studios
 */

#pragma once

#include <Client/Graphics/ChunkView.hpp>

#include <Common/Actor.hpp>

namespace phx
{
	/**
	 * @brief An object representing the player in a game
	 *
	 * Objects created by this class represent any player in the game, the
	 * player can be controlled by a camera object.
	 *
	 */
	class Player : public Actor
	{
	public:
		// temporary until a proper management system is put in place.
		explicit Player(voxels::ChunkView* world);

		math::Ray getTarget() const;

		bool action1();
		bool action2();

		void               setHand(voxels::BlockType* block);
		voxels::BlockType* getHand();

	private:
		float              m_reach = 32.f;
		voxels::ChunkView* m_world;
		voxels::BlockType* m_hand;
	};
} // namespace phx

