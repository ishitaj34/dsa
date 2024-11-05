''' To create ADT that implements the "set" concept:
1. Add (new element) - Place a value into the set 
2. Remove (element) - Remove the value 
3. Contains (element) - Return true if element is in collection
4. Size() - Return number of values in collection  
5. Iterator() - Return an iterator used to loop over collection
6. Intersection of two sets 
7. Union of two sets
8. Difference between two sets
9. Subset '''

l1 = []

def dup(d):
    lst = []
    
    for i in d:
        if i not in lst:
            lst.append(i)
            
    return lst

def read(l):
    n = int(input("\nEnter the number of elements to be inputted: "))
    
    for i in range(n):
        val = int(input("\nEnter an element: "))
        l.append(val)
    
    l = dup(l)
      
    print("\nList:", l)
    
def add():
	m = int(input("\nEnter the value to be added: "))
	l1.append(m)
	
	print("\nEdited list:", l1)
	
def remove():
	m = int(input("\nEnter the value to be removed: "))
	l1.remove(m)
	
	print("\nEdited list:", l1)
	
def contains():
	key = int(input("\nEnter the element to be searched: "))
	
	if key in l1:
		print("\nElement is present in the list.")
	else:
		print("\nElement is not present in the list.")
		
def size():
    c = 0
    myit = iter(l1)

    for i in myit:
        c += 1

    print("\nLength of list:", c)
 
def intersection():
    l2 = []
    intersect = []
	
    read(l2)
    l2 = dup(l2)
	
    for i in l1:
        for j in l2:
            if j == i:
                intersect.append(j)
	
    print("\nIntersection of two lists:", intersect)
 
def union():
    l3 = []
    union = l1.copy()
	
    read(l3)
    l3 = dup(l3)
	
    for i in l3:
        if i not in union:
            union.append(i)
			
    union = dup(union)
	
    print("\nUnion of two lists:", union)
 
def diff():
    l4 = []
    differ = []
    
    read(l4)
    l4 = dup(l4)
     
    for i in l1:
        if i not in l4:
            differ.append(i)
    
    differ = dup(differ)
    
    print("\nDifference of two list:", differ)
    
def sub():
    subset = []
    n = int(input("\nEnter the number of elements in the subset: "))
    
    for i in range(n):
        val = int(input("\nEnter an element in the subset: "))
        subset.append(val)
        
    for j in subset:
        if j not in l1:
            return False
    return True
        

print("\n\n*** MENU ***\n")
print("1. Add an element to the list")
print("2. Remove an element")
print("3. Search presence of an element")
print("4. Size of the list")
print("5. Intersection of two sets")
print("6. Union of two sets")
print("7. Difference between two lists")
print("8. Subset of a list")

read(l1)

a = 1
while a == 1:
    ch = int(input("\nEnter your choice: "))
    
    if ch == 1:
        add()
    elif ch == 2:
        remove()
    elif ch == 3:
        contains()
    elif ch == 4:
        size()
    elif ch == 5:
        intersection()
    elif ch == 6:
        union()
    elif ch == 7:
        diff()
    elif ch == 8:
        if sub():
            print("\nGiven subset is present in the list.")
        else:
            print("\nGiven subset is not present in the list.")
    else:
        print("\nInvalid choice.")
        
    ans = input("\nWould you like to continue? (y/n): ")
    if ans == 'y':
        a = 1
    else:
        a = 0
        print("\nThank you!")
        
    
    
    
    
