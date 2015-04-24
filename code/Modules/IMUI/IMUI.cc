//------------------------------------------------------------------------------
//  IMUI.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "IMUI.h"
#include "Core/Assertion.h"
#include "Core/Memory/Memory.h"

namespace Oryol {

IMUI::_state* IMUI::state = nullptr;

//------------------------------------------------------------------------------
void
IMUI::Setup() {
    o_assert_dbg(!IsValid());
    state = Memory::New<_state>();
    state->imguiWrapper.Setup();
}

//------------------------------------------------------------------------------
void
IMUI::Discard() {
    o_assert_dbg(IsValid());
    state->imguiWrapper.Discard();
    Memory::Delete(state);
    state = nullptr;
}

//------------------------------------------------------------------------------
void
IMUI::NewFrame(Duration frameDuration) {
    o_assert_dbg(IsValid());
    state->imguiWrapper.NewFrame(frameDuration);
}

} // namespace Oryol
