#!/usr/bin/env python3
import sqlite3
from collections import Counter
from os import getenv

l_verbose = False

def verbose_print(a_msg):
    if l_verbose:
        print(a_msg)

def create_header_file():
    l_template = '''
#include "book.h"
namespace bible{
    Book canon[31101] = {

'''
    with open("/tmp/bible.h", 'w') as b:
        b.write(l_template)


create_header_file()

conn = sqlite3.connect(getenv('HOME') + '/kjv.db')
c = conn.cursor()
c.execute('SELECT book, chapter, verse, text from kjv')

filehandler = open('/tmp/bible.h', 'a')
counter = 0
for row in c:
    l_obj = 'Book{\"%s\", %d, %d, \"%s\"},'%(row[0], row[1], row[2], row[3])
    filehandler.write(l_obj)
    counter+=1
    
print("counter: ", counter)
filehandler.close()
