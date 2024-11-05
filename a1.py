# Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client's telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.

l1 = []
l2 = []

m = int(input("\nEnter table size: "))

n = int(input("\nEnter the number of clients: "))

# To initialise l1 and l2 with five indices with value 'None'
for i in range(m):
    l1.append(None)
    l2.append(None)
    
def linear():
    for i in range(n):
        client = input("\nEnter the name of the client: ")
        tel = int(input("Enter the telephone number of the client: "))
        
        h = tel % m     # Hash formula to calculate hash value
        
        if l2[h] == None:     # No collision detected
            l1[h] = client
            l2[h] = tel
        else:     # Collision detected
            for j in range(h + 1, m):     # To check for an empty index between hash value and maximum size
                if l2[j] == None:
                    l1[j] = client
                    l2[j] = tel
                    break
            else:     # Wrap around condition
                for j in range(h):     # To check for an empty index from first index to hash value
                    if l2[j] == None:
                        l1[j] = client
                        l2[j] = tel
                        break
                    
def doublehash():
    for i in range(n):
        client = input("\nEnter the name of the client: ")
        tel = int(input("Enter the telephone number of the client: "))
		
        h1 = tel % m
        h = h1
		
        if l2[h1] == None:
            l1[h1] = client
            l2[h1] = tel
        else:
            index = 0
			
            while(1):
                if(l2[h] != None):
                    index+=1
					
                    h2 = 5 - (tel % 5)
                    h = (h1 + (index * h2)) % m
                else:
                    l1[h] = client
                    l2[h] = tel
                    break
                    
def display():
    print("\n\nHash Table:")
    print(" ----------------------------------------------")
    print("|  Index  |  Client Name  |  Telephone Number  |")
    print(" ----------------------------------------------")
    
    for i in range(m):
        if l1[i] != None and l2[i] != None:
            n = l1[i]
            t = l2[i]
        else:
            n = ' '
            t = ' '
            
        print(f"|  {i:^5}  |  {n:^11}  |  {t:^16}  |")
        
    print(" ----------------------------------------------")
    
def search1():
        key = int(input("\nEnter the telephone number of the client to be searched: "))
        
        h = key % m
        
        c = 0
        
        if key in l2:
            if l2[h] == key:
                c+=1
                print("\nClient is present in the book at index", h)
            else:
                for i in range(m):
                    c+=1
                    if l2[i] == key:
                        print("\nClient is present in the book at index", i)
        else:
            print("\nClient is not present in the database.")
            
        print("\nNumber of comparisons required: ", c)
            
def search2():
        key = int(input("\nEnter the telephone number of the client to be searched: "))
    
        h1 = key % m
        h = h1
        
        c = 0
        
        if key in l2:
            if l2[h1] == key:
                c+=1
                print("\nClient is present in the book at index", h)
            else:
                index = 0
			
                while(1):
                    if(l2[h] != None):
                        c+=1
                        index+=1
					
                        h2 = 5 - (key % 5)
                        h = (h1 + (index * h2)) % m
                    else:
                        print("\nClient is present in the book at index", h)
                        break
        else:
            print("\nClient is not present in the database.")
            
        print("\nNumber of comparisons required: ", c)
            
                
print("\n\n*** MENU ***\n")
print("1. Input information in the hash table using linear probing")
print("2. Input information in the hash table using double hashing")
print("3. Search the hash table using linear probing")
print("4. Search the hash table using double hashing")


a = 1
while a == 1:
    ch = int(input("\nEnter your choice: "))
    
    if ch == 1:
        linear()
        display()
        
    elif ch == 2:
        doublehash()
        display()
        
    elif ch == 3:
        search1()
        
    elif ch == 4:
        search2()
        
    else:
        print("\nInvalid choice.")
        
    q = input("\nWould you like to continue?(y/n): ")
    if q == 'y':
        a = 1
        print("\n")
    else:
        a = 0
        print("\nThank you!\n")
        
