#!/usr/bin/env python
#-*- coding: utf-8 -*-
'''
    python ==>
'''
import sys

fd = open(sys.argv[1],"rb")
dll_contents = fd.read()
fd.close()

print "[*] File Size : %d" % len(dll_contents)

fd = open("%s:%s" % (sys.argv[2],sys.argv[1]),"wb")
fd.write(dll_contents)
fd.close()