#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 11:40:36 2019

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
        node.next = self.head
        self.head = node
        
        
    def delete(self):
         last = self.head
         
         if self.head is None:
             print("List underflow")
             return
         
         while last.next:
             previous = last
             last = last.next
             
         previous.next = None
         del last
        
    def print_list(self):
        last = self.head
        print("Your final list is:")
        
        if self.head is None:
            print("List is empty")
            return
        
        while last:
            print(last.data)
            last = last.next
            
            
my_list = LinkedList()

while True:
    print("\nWhat do you want to do?\n1. Insert at  beginning\n2. Delete at tail\n3. Print list\n4. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice is 1:
        my_list.insert()
        
    elif choice is 2:
        my_list.delete()
        
    elif choice is 3:
        my_list.print_list()
        
    elif choice is 4:
        break
    else:
        print("Invalid input")
    
        


















