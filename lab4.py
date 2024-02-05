class Student: 
    L = ["ab", 20]

    def change_name(self, name):
        self.L[0] = name


s1 = Student() 
print(id(s1.L[0]))
print(id(s1.L))
print(s1.L[0])


s1.L[0] = "cd"
print(s1.L[0])

s1.change_name("Allan")
print(s1.L[0])

# cannot access things by addresses, you can directly
# access the s1 instance of Student and change its properties 

"""
Memory Diagram 

Address Value 
1000    s1 
1000    s1.L
1001    s1.L[0] -> changes applied here     
1002    ...
1003    ...
1004    change_name in Student
1005    

"""