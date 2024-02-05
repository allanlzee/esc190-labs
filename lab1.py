global a

def change_a(): 
    global a
    
    a = 10 


def change_arr_index(array, index, value):
    array[index] = value

    return array

a = 5 
print(a)
change_a()
print(a)

arr = [0] * 100 
new_arr = change_arr_index(arr, 1, 10)
print(new_arr)