def swap(x, y):
    return y, x

def selection_sort(arr):
    n = len(arr)
    # One by one move boundary of unsorted subarray
    for i in range(n - 1):
        # Find the minimum element in the unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum element with the first element
        if min_idx != i:
            arr[i], arr[min_idx] = swap(arr[i], arr[min_idx])

def print_array(arr):
    for num in arr:
        print(num, end=" ")
    print()

# Driver code to test the above functions
if __name__ == "__main__":
    arr = [64, 25, 12, 22, 11]
    
    selection_sort(arr)
    
    print("Sorted array:")
    print_array(arr)
