#!/usr/bin/env python3
import sqlite3
from collections import Counter
from os import getenv

#################
# CREATE book.h #
#################
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
# print(cstring_result)

##################################
# Create other book header files #
##################################
file_template = '''
#ifndef {header_name}_H
#define {header_name}_H

#include <string>
#include "book.h"

class {class_name} : public {base_class_name} {{ // uppercase
public:
const std::string book_name = "{header_name}"; // caps

'''

book_name_holder = 'GENESIS'
book_chapter_marker = 1
c.execute('SELECT book, chapter, verse, text from kjv')
dirpath = "/tmp/"
filehandler = ''
filepath = ''
A_obj_str = ''
def create_header_file(a_file_path, a_book_name, a_template):
    # returns the filehandler
    f = open(a_file_path.lower(), 'a')
    f.write(a_template.format(header_name=a_book_name.upper(), class_name=a_book_name.capitalize(), base_class_name="Book"))
    return f

chapter_holder = ""
book_payload = ""
for row in c:
    # import pdb;pdb.set_trace()
    # if its a new chapter, add the },
    # if row[0] == "EXODUS":
    #     import pdb;pdb.set_trace()

    if book_name_holder != row[0]:
        # import pdb;pdb.set_trace()
        l_header_file = "{}.h".format(book_name_holder.lower())
        print("#include \"{}\"".format(l_header_file))
        filehandler = create_header_file(dirpath+"{}.h".format(book_name_holder),
                                         book_name_holder,
                                         file_template)
        
        # filehandler.write('A books[{}][{}] = {{'.format(l_max_chapter_map[book_name_holder], l_max_verse_map[book_name_holder]))
        filehandler.write('A books[{}][{}] = {{'.format(200, 200))        
        # probably subtract the last comma off the real payload , then write the payload generated..
        # PLACEHOLDER
        book_payload = book_payload[:-1]
        filehandler.write(book_payload)
        filehandler.write('};\n')
        # close out the file
        filehandler.write('};\n')
        filehandler.write('#endif')
        
        # Reset payload
        book_payload = ""
        # Set the new book name
        book_name_holder = row[0]
        # Reset chapter
        book_chapter_marker = 1

    # IF its a new chapter, close it off with brackets and comma
    if book_chapter_marker != row[1]:
        # import pdb;pdb.set_trace()
        # import pdb;pdb.set_trace()
        book_payload = book_payload[:-1] # remove tailing comma
        book_payload = '{%s},'%(book_payload)
        book_chapter_marker = row[1]
    
    # else continue making the payload
    book_payload += '{%d, %d, "%s"},'%(row[1], row[2], row[3])
    # import pdb;pdb.set_trace()
        
