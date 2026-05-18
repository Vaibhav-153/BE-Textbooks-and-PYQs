def bubbleSort(arr):
    n = len(arr)
    
    for i in range(n-1):
        swapped = False
        
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        
        if not swapped:
            return

# Driver code to test above
arr = [64, 34, 25, 12, 22, 11, 90]
bubbleSort(arr)
print("Sorted array is:", arr)

def ternary_search(left_index, right_index, search_key, list_vals):
    if right_index >= left_index:
        mid_index1 = left_index + (right_index - left_index) // 3
        mid_index2 = right_index - (right_index - left_index) // 3

        if list_vals[mid_index1] == search_key:
            return mid_index1
        if list_vals[mid_index2] == search_key:
            return mid_index2

        if search_key < list_vals[mid_index1]:
            return ternary_search(left_index, mid_index1 - 1, search_key, list_vals)
        elif search_key > list_vals[mid_index2]:
            return ternary_search(mid_index2 + 1, right_index, search_key, list_vals)
        else:
            return ternary_search(mid_index1 + 1, mid_index2 - 1, search_key, list_vals)
    return -1

if __name__ == "__main__":
    list_vals = [10, 20, 30, 40, 50, 60, 70, 80]
    key = int(input("Please enter a number:"))
    left_index = 0
    right_index = len(list_vals) - 1
    result = ternary_search(left_index, right_index, key, list_vals)
    print("Key is found at index:", result)

