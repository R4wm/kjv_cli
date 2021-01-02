#!/usr/bin/env python3
import sqlite3
from collections import Counter
from os import getenv

l_verbose = False

l_max_verse_map = Counter()
l_max_chapter_map = Counter()

conn = sqlite3.connect(getenv('HOME') + '/kjv.db')
c = conn.cursor()
c.execute('SELECT book, chapter, verse from kjv')

for row in c:
    if l_verbose: print(row)

    if l_max_chapter_map[row[0]] < row[1]:
        l_max_chapter_map[row[0]] = row[1]

    if l_max_verse_map[row[0]] < row[2]:
        l_max_verse_map[row[0]] = row[2]

# print(l_max_verse_map)
# print(l_max_chapter_map)

cstring_result = 'const std::map<std::string, book_meta> book_borders = {'
for key, val in l_max_chapter_map.items():
    cstring_result += '{\"%s\", book_meta{%d, %d}},'%(key, val, l_max_verse_map[key])

#dirty hack
cstring_result = cstring_result[:-1]
cstring_result += '};'
print(cstring_result)
