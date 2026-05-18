def intersection(cricket, badminton):
    res = []
    for student in cricket:
        if student in badminton:
            res.append(student)
    return res

def union(cricket, badminton):
    res = badminton.copy()
    for student in cricket:
        if student not in badminton:
            res.append(student)
    return res

def difference(cricket, badminton):
    res = []
    for student in cricket:
        if student not in badminton:
            res.append(student)
    return res

def students_cricket_and_football(cricket, football, badminton):
    res = []
    for student in cricket:
        if student in football and student not in badminton:
            res.append(student)
    return res

group_A = [1, 2, 3, 4, 5, 6, 7]  # Students who play cricket
group_B = [2, 3, 6, 7, 10]      # Students who play badminton
group_C = [2, 4, 6, 8, 10, 12]   # Students who play football

# a) List of students who play both cricket and badminton
print(f"a) List of students who play both cricket and badminton: {intersection(group_A, group_B)}")

# b) List of students who play either cricket or badminton but not both
union_ab = union(group_A, group_B)
intersection_ab = intersection(group_A, group_B)
print(f"b) List of students who play either cricket or badminton but not both: {difference(union_ab, intersection_ab)}")

# c) Number of students who play neither cricket nor badminton
difference_cb = difference(group_C, group_B)
print(f"c) Number of students who play neither cricket nor badminton: {len(difference(difference_cb, group_A))}")

# d) Number of students who play cricket and football but not badminton
print(f"d) Number of students who play cricket and football but not badminton: {students_cricket_and_football(group_A, group_C, group_B)}")
