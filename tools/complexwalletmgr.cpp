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

int main() {
  int value = 0;
  auto action = [&] { value++; };
  auto action_renderer =
      Renderer([&] { return text("count = " + std::to_string(value)); });

  auto buttons =
                   Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Simple 1", action, ButtonOption::Simple()),
                  Button("Simple 2", action, ButtonOption::Simple()),
                  Button("Simple 3", action, ButtonOption::Simple()),
              }),
              Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Animated 1", action, ButtonOption::Animated()),
                  Button("Animated 2", action, ButtonOption::Animated()),
                  Button("Animated 3", action, ButtonOption::Animated()),
              }),
              Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Animated 4", action,
                         ButtonOption::Animated(Color::Red)),
                  Button("Animated 5", action,
                         ButtonOption::Animated(Color::Green)),
                  Button("Animated 6", action,
                         ButtonOption::Animated(Color::Blue)),
              }),
          }),
      }) |
      border;
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(buttons);
  return 0;
}

