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

/***
 * @file ImGuiHelpers.hpp
 * @describe
 *   defines objects that implement alternative ImGui interfaces for easier
 *   UI implementation.
 */

#pragma once

#include <imgui.h>
#include <imgui_internal.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// NOTE: consider transfering to an ANSI.h for submodule context, this code
//   could possibly be used with an alternative GUI API as well and could
//   benefit from being standalone.
#define ANSI_RED IM_COL32(255, 0, 0, 255)

namespace q2
{
	namespace ImGuiHelpers
	{
		class ImOOGuiWindow
		{
		protected:
			const char*            rootWindowName;
			const ImGuiWindowFlags defaultFlags = ImGuiWindowFlags_None;
			explicit ImOOGuiWindow(const char* name) { rootWindowName = name; };

		public:
			inline void begin(bool* p_open, ImGuiWindowFlags flags)
			{
				ImGui::Begin(rootWindowName, p_open, flags);
			}
			inline void end() { ImGui::End(); }

			// NOTE: define overrides in base class for ease of implementation
			// down the road.
			//       WARNING: This will not work unless the drawEx funcion is
			//       virtual for runtime
			//                inheritance checking purposes. Otherwise it will
			//                always point to this classes unused version.
			//
			// TODO: vertical shrink with templates
			inline void draw() { drawEx(NULL, ImGuiWindowFlags_None); };
			inline void draw(bool* p_open)
			{
				drawEx(p_open, ImGuiWindowFlags_None);
			};
			inline void draw(bool* p_open, ImGuiWindowFlags flags)
			{
				drawEx(p_open, flags);
			};

			virtual inline void drawEx(bool* p_open, ImGuiWindowFlags flags) {
			    /*TODO: throw error must override */};
		};

		class BasicTerminal : public ImOOGuiWindow
		{
		private:
			// Because we don't currently have a C++ standard facility for
			// piping output into a statically allocated string or string_view.
			// May want to investigate a change here if we upgrade to C++20
			void flush();
			// For spliting GPU logic from CPU logic. In case no data is pushed
			// in one frame we can avoid senseless resizes.
			// When this is eventually made thread-safe and the renderer is set
			// apart from the game logic, should allow for more than one
			// buffer push to happen before the end of a frame.
			// Also, we should investigate deriving a custom std::stringbuf
			// to get access to the underlying string in our std::ostringstream
			// instead of copying the damn thing and emptying it for every flush
			// operation. It may also remove the necessity of the flush call
			// period.
			int targetOutputSize;
			// display cache (perhaps should rename to OutputBuffer)
			std::string cache;
			std::string inputBuffer;

		protected:
			const char*                   outputWindowName;
			static const ImGuiWindowFlags defaultFlags =
			    ImGuiWindowFlags(ImGuiWindowFlags_NoScrollbar |
			                     ImGuiWindowFlags_NoScrollWithMouse);

			void drawInputField();
			void drawOutputField(ImGuiWindowFlags flags);

		public:
			// append at end mode (basically the same as stdout)
			std::ostringstream cout;

			inline BasicTerminal(const char* name, int outputKiloBytes,
			                     const char* initialContents)
			    : ImOOGuiWindow(name)
			{
				outputWindowName = std::string(name).append("_Output").c_str();
				targetOutputSize = outputKiloBytes * 1024; // align to kilobytes
				inputBuffer      = std::string("");
				cache            = initialContents;
				cache.reserve(targetOutputSize);
				cout =
				    std::ostringstream(std::ios_base::out | std::ios_base::ate);
			}

			inline BasicTerminal(const char* name, int outputKiloBytes)
			    : ImOOGuiWindow(name)
			{
				outputWindowName = std::string(name).append("_Output").c_str();
				targetOutputSize = outputKiloBytes * 1024; // align to kilobytes
				inputBuffer      = std::string("");
				cache            = std::string("");
				cache.reserve(targetOutputSize);
				cout =
				    std::ostringstream(std::ios_base::out | std::ios_base::ate);
			}

			inline ~BasicTerminal() {};

			virtual void drawEx(bool* p_open, ImGuiWindowFlags flags);
			virtual void onCommand(std::string input);
		};
	}; // namespace ImGuiHelpers
};     // namespace q2
