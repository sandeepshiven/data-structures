#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 10:05:09 2019

@author: sandeep
"""

'''
program to insert a node at end and delete node from the head
basically it is implementation of a queue using linked list
where insertion occur at one end i.e. tail and deletion occur 
at head, queue follows the First in First out approach

'''


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
        
        if self.head is None:
            self.head = node
            return
        
        last = self.head
        
        while last.next:
            last = last.next
            
        last.next = node
        
    def delete(self):
        last = self.head
        
        if self.head is None:
            print("List underflow\n")
            return
        self.head = last.next
        del last
        
        
    def print_list(self):
        last = self.head
        print("Your final list is:")
        if self.head is None:
            print("List is empty\n")
            return
        
        while last:
            print(last.data)
            last = last.next
            
            
            
my_list = LinkedList()

while True:
    print("\nWhat do you want to do?\n1. Insert at end\n2. Delete at head\n3. Print list\n4. Exit")
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
        
        
        
        
        
        
    




















