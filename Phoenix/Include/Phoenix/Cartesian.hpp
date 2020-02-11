// Copyright 2019 Genten Studios
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
 * @brief Types and conversion functions for various coordinate systems.
 */

#pragma once

#include <Phoenix/Math/Vector3.hpp>
#include <Phoenix/Math/Math.hpp>
#include <Phoenix/Voxels/Chunk.hpp>

namespace phx
{
    /**
     * @brief Player coordinates
     */
    class PosPlayer : public math::detail::Vector3<float>{
    public:
        PosPlayer(math::vec3 pos){
            x = pos.x;
            y = pos.y;
            z = pos.z;
        };
    };
    /**
     * @brief Block coordinates
     */
    class PosBlock : public math::detail::Vector3<int>{
    public:
        PosBlock(math::vec3 pos){
            x = std::floor(pos.x);
            y = std::floor(pos.y);
            z = std::floor(pos.z);
        };
        PosBlock(PosPlayer pos){
            pos = (pos / 2.f) - .5f;
            x = std::floor(pos.x);
            y = std::floor(pos.y);
            z = std::floor(pos.z);
        };
        operator PosPlayer(){
            return (this + 0.5f) * 2.f;
        };
    };
    /**
     * @brief Chunk coordinates
     */
    class PosChunk : public math::detail::Vector3<int>{
    public:
        PosChunk(math::vec3 pos){
            x = pos.x;
            y = pos.y;
            z = pos.z;
        };
        PosChunk(PosBlock pos){
            x = std::floor(pos.x / voxels::Chunk::CHUNK_WIDTH);
            y = std::floor(pos.y / voxels::Chunk::CHUNK_HEIGHT);
            z = std::floor(pos.z / voxels::Chunk::CHUNK_DEPTH);
        };
        PosChunk(PosPlayer pos){
            pos = (pos / 2.f) - .5f;
            x = std::floor(pos.x / voxels::Chunk::CHUNK_WIDTH);
            y = std::floor(pos.y / voxels::Chunk::CHUNK_HEIGHT);
            z = std::floor(pos.z / voxels::Chunk::CHUNK_DEPTH);
        };
    };
    /**
     * @brief Block coordinates relative to a chunk
     */
    class InChunk : public math::detail::Vector3<int>{
    public:
        InChunk(math::vec3 pos){
            x = pos.x;
            y = pos.y;
            z = pos.z;
        };
        InChunk(PosBlock pos){
            x = pos.x % voxels::Chunk::CHUNK_WIDTH;
            y = pos.y % voxels::Chunk::CHUNK_HEIGHT;
            z = pos.z % voxels::Chunk::CHUNK_DEPTH;
        };
//        PosBlock(PosChunk chunk, InChunk block){
//            x = (chunk.x * voxels::Chunk::CHUNK_WIDTH) + block.x;
//            y = (chunk.y * voxels::Chunk::CHUNK_HEIGHT) + block.y;
//            z = (chunk.z * voxels::Chunk::CHUNK_DEPTH) + block.z;
//        };
    };
}