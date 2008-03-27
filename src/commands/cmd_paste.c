/* ASE - Allegro Sprite Editor
 * Copyright (C) 2001-2008  David A. Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "config.h"

#include "commands/commands.h"
#include "modules/sprites.h"
#include "raster/sprite.h"
#include "raster/undo.h"
#include "util/clipbrd.h"

static bool cmd_paste_enabled(const char *argument)
{
  Sprite *sprite = current_sprite;
  Sprite *clipboard = get_clipboard_sprite();

  return (sprite && clipboard && (clipboard != sprite));
}

static void cmd_paste_execute(const char *argument)
{
  if (undo_is_enabled(current_sprite->undo))
    undo_set_label(current_sprite->undo, "Paste");

  paste_from_clipboard();
}

Command cmd_paste = {
  CMD_PASTE,
  cmd_paste_enabled,
  NULL,
  cmd_paste_execute,
  NULL
};
