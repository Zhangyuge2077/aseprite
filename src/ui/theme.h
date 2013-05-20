// ASEPRITE gui library
// Copyright (C) 2001-2013  David Capello
//
// This source file is distributed under a BSD-like license, please
// read LICENSE.txt for more information.

#ifndef UI_THEME_H_INCLUDED
#define UI_THEME_H_INCLUDED

#include "ui/base.h"
#include "ui/cursor_type.h"

struct BITMAP;
struct FONT;

namespace gfx {
  class Region;
}

namespace ui {

  class Cursor;
  class PaintEvent;
  class Widget;

  class Theme
  {
  public:
    const char* name;
    struct FONT* default_font;
    int scrollbar_size;
    int guiscale;

    Theme();
    virtual ~Theme();

    void regenerate();

    virtual Cursor* getCursor(CursorType type) = 0;
    virtual void initWidget(Widget* widget) = 0;
    virtual void getWindowMask(Widget* widget, gfx::Region& region) = 0;
    virtual void setDecorativeWidgetBounds(Widget* widget) = 0;

    virtual void paintDesktop(PaintEvent& ev) = 0;
    virtual void paintBox(PaintEvent& ev) = 0;
    virtual void paintButton(PaintEvent& ev) = 0;
    virtual void paintCheckBox(PaintEvent& ev) = 0;
    virtual void paintEntry(PaintEvent& ev) = 0;
    virtual void paintGrid(PaintEvent& ev) = 0;
    virtual void paintLabel(PaintEvent& ev) = 0;
    virtual void paintLinkLabel(PaintEvent& ev) = 0;
    virtual void paintListBox(PaintEvent& ev) = 0;
    virtual void paintListItem(PaintEvent& ev) = 0;
    virtual void paintMenu(PaintEvent& ev) = 0;
    virtual void paintMenuItem(PaintEvent& ev) = 0;
    virtual void paintSplitter(PaintEvent& ev) = 0;
    virtual void paintRadioButton(PaintEvent& ev) = 0;
    virtual void paintSeparator(PaintEvent& ev) = 0;
    virtual void paintSlider(PaintEvent& ev) = 0;
    virtual void paintComboBoxEntry(PaintEvent& ev) = 0;
    virtual void paintComboBoxButton(PaintEvent& ev) = 0;
    virtual void paintTextBox(PaintEvent& ev) = 0;
    virtual void paintView(PaintEvent& ev) = 0;
    virtual void paintViewScrollbar(PaintEvent& ev) = 0;
    virtual void paintViewViewport(PaintEvent& ev) = 0;
    virtual void paintWindow(PaintEvent& ev) = 0;
    virtual void paintPopupWindow(PaintEvent& ev) = 0;
    virtual void paintTooltip(PaintEvent& ev) = 0;

  protected:
    virtual void onRegenerate() = 0;
  };

  namespace CurrentTheme
  {
    void set(Theme* theme);
    Theme* get();
  }

  BITMAP* ji_apply_guiscale(BITMAP* original);

  // This value is a factor to multiply every screen size/coordinate.
  // Every icon/graphics/font should be scaled to this factor.
  inline int jguiscale()
  {
    return CurrentTheme::get() ? CurrentTheme::get()->guiscale: 1;
  }

} // namespace ui

#endif
