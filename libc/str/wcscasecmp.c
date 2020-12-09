/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ This program is free software; you can redistribute it and/or modify         │
│ it under the terms of the GNU General Public License as published by         │
│ the Free Software Foundation; version 2 of the License.                      │
│                                                                              │
│ This program is distributed in the hope that it will be useful, but          │
│ WITHOUT ANY WARRANTY; without even the implied warranty of                   │
│ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU             │
│ General Public License for more details.                                     │
│                                                                              │
│ You should have received a copy of the GNU General Public License            │
│ along with this program; if not, write to the Free Software                  │
│ Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA                │
│ 02110-1301 USA                                                               │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/str/str.h"

/**
 * Compares NUL-terminated wide strings case-insensitively.
 *
 * @param a is first non-null NUL-terminated string pointer
 * @param b is second non-null NUL-terminated string pointer
 * @return is <0, 0, or >0 based on uint8_t comparison
 * @asyncsignalsafe
 */
int wcscasecmp(const wchar_t *a, const wchar_t *b) {
  size_t i = 0;
  unsigned x, y;
  if (a == b) return 0;
  while ((x = tolower(a[i])) == (y = tolower(b[i])) && b[i]) ++i;
  return x - y;
}