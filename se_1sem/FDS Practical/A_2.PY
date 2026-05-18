marklist = [20, 20, 27, 94, None, 20, 57, None, 10, 57, 20, None, 91, 94, 56, None]

total = 0
absent_student = 0
max_val = min_val = marklist[0]

# Calculate total, number of absent students, highest and lowest scores
for mark in marklist:
    if mark is None:
        absent_student += 1
    else:
        total += mark
        if mark < min_val:
            min_val = mark
        if mark > max_val:
            max_val = mark

# Calculate average score
average_score = total / len([mark for mark in marklist if mark is not None])

print(f"a. Average score of the class: {average_score}")
print(f"b. Highest score = {max_val} and Lowest score = {min_val}")
print(f"c. Number of absent students: {absent_student}")

# Calculate frequency
freq = {}
for mark in marklist:
    if mark is not None:
        if mark not in freq:
            freq[mark] = 1
        else:
            freq[mark] += 1

# Find the mark with the highest frequency
highest_freq = 0
highest_freq_mark = None

for mark in freq:
    if freq[mark] > highest_freq:
        highest_freq = freq[mark]
        highest_freq_mark = mark

print(f"d. Marks with the Highest frequency: {highest_freq_mark}")
