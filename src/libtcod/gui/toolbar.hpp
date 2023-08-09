/* BSD 3-Clause License
 *
 * Copyright © 2008-2023, Jice and the libtcod contributors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TCOD_GUI_TOOLBAR_HPP
#define TCOD_GUI_TOOLBAR_HPP
#ifndef TCOD_NO_UNICODE
#include <string.h>

#include <algorithm>
#include <string>

#include "../console_printing.hpp"
#include "container.hpp"

class ToolBar : public Container {
 public:
  ToolBar(int x, int y, const char* name, const char* tip = nullptr) : Container(x, y, 0, 2) {
    if (name) {
      this->name = TCOD_strdup(name);
      w = static_cast<int>(strlen(name) + 4);
    }
    if (tip) setTip(tip);
  }
  ToolBar(int x, int y, int w, const char* name, const char* tip = nullptr) : Container(x, y, w, 2), fixedWidth(w) {
    if (name) {
      this->name = TCOD_strdup(name);
      fixedWidth = w = std::max<int>(static_cast<int>(strlen(name) + 4), w);
    }
    if (tip) setTip(tip);
  }
  ~ToolBar() {
    if (name) free(name);
  }
  void render() {
    con->setDefaultBackground(back);
    con->setDefaultForeground(fore);
    if (name) {
      TCOD_console_printf_frame(con->get_data(), x, y, w, h, true, TCOD_BKGND_SET, "%s", name);
    }
    Container::render();
  }
  void setName(const char* name_) {
    if (this->name) free(this->name);
    if (name_) {
      this->name = TCOD_strdup(name_);
      fixedWidth = std::max<int>(static_cast<int>(strlen(name_) + 4), fixedWidth);
    } else {
      this->name = nullptr;
    }
  }

  void addSeparator(const char* txt, const char* tip = nullptr) { addWidget(std::make_unique<Separator>(txt, tip)); }
  void computeSize() {
    int cury = y + 1;
    w = name ? static_cast<int>(strlen(name) + 4) : 2;
    for (auto& wid : content_) {
      if (wid->isVisible()) {
        wid->x = x + 1;
        wid->y = cury;
        wid->computeSize();
        if (wid->w + 2 > w) w = wid->w + 2;
        cury += wid->h;
      }
    }
    if (w < fixedWidth) w = fixedWidth;
    h = cury - y + 1;
    for (auto& wid : content_) {
      if (wid->isVisible()) {
        wid->expand(w - 2, wid->h);
      }
    }
  }

 protected:
  char* name{};
  int fixedWidth{0};

 private:
  struct Separator : public Widget {
    Separator(const char* txt, const char* tip = nullptr) : Widget(0, 0, 0, 1) {
      if (txt) {
        this->txt = TCOD_strdup(txt);
      }
      if (tip) setTip(tip);
    }
    virtual ~Separator() {
      if (txt) {
        free(txt);
      }
    }
    void computeSize() { w = txt ? static_cast<int>(strlen(txt) + 2) : 0; }
    void expand(int width, int) { w = std::max(w, width); }
    void render() {
      auto& console = static_cast<TCOD_Console&>(*con);
      const auto fg = TCOD_ColorRGB(fore);
      const auto bg = TCOD_ColorRGB(back);
      tcod::draw_rect(console, {x, y, w, 1}, 0x2500, fg, bg);
      if (console.in_bounds({x - 1, y})) {
        console.at({x - 1, y}) = {0x251C, {fg.r, fg.g, fg.b, 255}, {bg.r, bg.g, bg.b, 255}};  // ├
      }
      if (console.in_bounds({x + w, y})) {
        console.at({x + w, y}) = {0x2524, {fg.r, fg.g, fg.b, 255}, {bg.r, bg.g, bg.b, 255}};  // ┤
      }
      tcod::print(console, {x + w / 2, y}, tcod::stringf(" %s ", txt), bg, fg, TCOD_CENTER);
    }
    char* txt{};
  };
};
#endif  // TCOD_NO_UNICODE
#endif /* TCOD_GUI_TOOLBAR_HPP */
