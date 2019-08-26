#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 00:34:13 2019

@author: sandeep
"""

class Node():
    def __init__(self):
        self.data = None
        self.next = None

class LinkedList():
    def __init__(self):
        self.head = None
        
    def insert(self):
        num = int(input("Enter a number: "))
        node = Node()
        node.data = num
        
        if self.head == None:
            self.head = node
            return
        last = self.head
        
        while last.next:
            last = last.next
        
        last.next = node
        
    def print_list(self):
        
        current = self.head
        
        
        print("\nYour final list is:")
        
        if self.head == None:
            print("List is empty\n")
            return
        
        while current:
            print(current.data)
            current = current.next
        
        
        
            



my_list = LinkedList()

while True:
    print("\nWhat do you want to do?\n1. Insert at end\n2. Print list\n3. End")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        my_list.insert()
        
    elif choice == 2:
        my_list.print_list()
        
    elif choice == 3:
        break
    else:
        print("Invalid Choice\n")
    

















