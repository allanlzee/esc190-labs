# Binary Search Deluxe 
def binary_search_deluxe_left(L, target): 
    L = sorted(L)

    left = 0
    right = len(L) - 1
    while left <= right:
        mid = (left + right) // 2
            
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left


def binary_search_deluxe(L, target) -> tuple: 
    # Assume L is already sorted. 

    left_l = 0
    right_l = len(L) - 1

    while left_l <= right_l:
        mid = (left_l + right_l) // 2
            
        if L[mid] < target:
            left_l = mid + 1
        else:
            right_l = mid - 1

    left_r = 0
    right_r = len(L) - 1

    while left_r <= right_r:
        mid = (left_r + right_r) // 2
            
        if L[mid] > target:
            right_r = mid - 1
        else:
            left_r = mid + 1

    return [left_l, right_r]


if __name__ == "__main__":
    print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 12))

