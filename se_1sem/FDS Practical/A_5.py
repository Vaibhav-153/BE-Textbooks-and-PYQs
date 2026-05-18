# Function for Selection Sort of elements
def Selection_Sort(marks):
    for i in range(len(marks)):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j
        # Swap the minimum element with the first element
        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    print("Marks of students after performing Selection Sort on the list:")
    for i in range(len(marks)):
        print(marks[i])

# Function for Bubble Sort of elements
def Bubble_Sort(marks):
    n = len(marks)
    # Traverse through all array elements
    for i in range(n - 1):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Marks of students after performing Bubble Sort on the list:")
    for i in range(len(marks)):
        print(marks[i])

# Function for displaying top five marks
def top_five_marks(marks):
    print("Top", len(marks), "Marks are:")
    print(*marks[::-1], sep="\n")

# Main
marks = []
n = int(input("Enter the number of students whose marks are to be displayed: "))
print("Enter marks for", n, "students (Press SPACE after every student's marks): ")
marks_input = input().split()  # Input as space-separated values
for i in range(0, n):
    ele = int(marks_input[i])
    marks.append(ele)  # adding the element

print("The marks of", n, "students are:")
Selection_Sort(marks.copy())  # Displaying marks before sorting
Bubble_Sort(marks.copy())      # Displaying marks after Bubble Sort
top_five_marks(marks.copy())   # Displaying top five marks
