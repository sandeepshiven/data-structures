#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 12:14:47 2019

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
        node = Node()
        node.data = int(input("Enter a number: "))
        pos = int(input("Enter the position you want to insert the node: "))
        
        if pos is 1:
            node.next = self.head
            self.head  = node
            return
        
        last = self.head
        
        for i in range(pos-2):
            last = last.next
        
        successor = last.next
        last.next = node
        node.next = successor
        
        
    def delete(self):
        last = self.head
        pos = int(input("Enter the position you want to delete: "))
        if pos is 1:
            self.head = last.next
            del last
            return
        
        for i in range(pos-2):
            last = last.next
            
        successor = last.next
        last.next = successor.next
        del successor
        
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
    print("\nWhat do you want to do?\n1. Insert node\n2. Delete node\n3. Print list\n4. Exit")
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
        print("Invalid Choice")
    




















