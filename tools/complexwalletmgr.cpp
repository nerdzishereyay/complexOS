// Wallet manager, stores passwords/valuable information



#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include <utility>
#include <vector>
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/dom/elements.hpp"

/*
std::string logo = 
    R"(        ____   _____  __          __   _ _      _     __  __                                   
       / __ \ / ____| \ \        / /  | | |    | |   |  \/  |                                  
   ___| |  | | (___    \ \  /\  / /_ _| | | ___| |_  | \  / | __ _ _ __   __ _  __ _  ___ _ __ 
  / __| |  | |\___ \    \ \/  \/ / _` | | |/ _ \ __| | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__|
 | (__| |__| |____) |    \  /\  / (_| | | |  __/ |_  | |  | | (_| | | | | (_| | (_| |  __/ |   
  \___|\____/|_____/      \/  \/ \__,_|_|_|\___|\__| |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_|   
                                                                                __/ |          
                                                                               |___/           
)";

using namespace ftxui;


int main() {
  auto Buttons = 
    Container::Vertical({
          Container::Horizontal({
                  Button("Create", , ButtonOption::Ascii()),
                  Button("List", action2, ButtonOption::Ascii()),
                  Button("Delete", action3, ButtonOption::Ascii()),
          }),
      }) | border;
  Element
  auto screen = ScreenInteractive::Fullscreen();
  std::system("clear");
  screen.Loop(Buttons);
  return 0;
}
 
*/
// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

using namespace ftxui;

// This is a helper function to create a button with a custom style.
// The style is defined by a lambda function that takes an EntryState and
// returns an Element.
// We are using `center` to center the text inside the button, then `border` to
// add a border around the button, and finally `flex` to make the button fill
// the available space.
ButtonOption Style() {
  auto option = ButtonOption::Animated();
  option.transform = [](const EntryState& s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
}

int main() {
  int value = 50;

  // clang-format off
  auto btn_dec_01 = Button("-1", [&] { value -= 1; }, Style());
  auto btn_inc_01 = Button("+1", [&] { value += 1; }, Style());
  auto btn_dec_10 = Button("-10", [&] { value -= 10; }, Style());
  auto btn_inc_10 = Button("+10", [&] { value += 10; }, Style());
  // clang-format on

  // The tree of components. This defines how to navigate using the keyboard.
  // The selected `row` is shared to get a grid layout.
  int row = 0;
  auto buttons = Container::Vertical({
      Container::Horizontal({btn_dec_01, btn_inc_01}, &row) | flex,
      Container::Horizontal({btn_dec_10, btn_inc_10}, &row) | flex,
  });

  // Modify the way to render them on screen:
  auto component = Renderer(buttons, [&] {
    return vbox({
               text("value = " + std::to_string(value)),
               separator(),
               buttons->Render() | flex,
           }) |
           flex | border;
  });

  auto screen = App::FitComponent();
  screen.Loop(component);
  return 0;
}
