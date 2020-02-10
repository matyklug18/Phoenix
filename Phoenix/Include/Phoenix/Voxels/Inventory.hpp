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

#pragma once

#include <Phoenix/Voxels/Item.hpp>

namespace phx::voxels{
    class Inventory{
    public:
        Inventory(int size) : m_size(size) {};

        /**
         * @brief Adds an item to a slot
         * @param item The item to be added
         * @param slot The slot for the item to go to
         * @return
         * @true If the item was added to the slot
         * @false If the slot was full or already had a different item type
         */
        bool add(Item item, int slot);
        /**
         * @brief Gets what item is in the slot without removing from inventory
         * @param slot Which slot we are getting from
         * @return The items in the slot
         */
        Item get(int slot);
        /**
         * @brief Removes all items from a slot
         *
         * @param slot The slot to get the items from
         * @return The items from the slot
         */
        Item remove(int slot);
        /**
         * @brief Removes a portion of items from a slot
         * @param slot The slot to get the items from
         * @param num The number of items to remove from the slot
         * @return The removed items
         */
        Item remove(int slot, int num);

    private:
        std::vector<Item> m_items;
        size_t m_size;
    };
}