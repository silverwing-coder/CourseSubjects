# import random
import numpy as np

# vector_A = np.random.randint(10, size=25)
# print(vector_A)
# # vector_B = np.zeros(len(vector_A))
# vector_B = []
# for i in range(len(vector_A)):
#     if vector_A[i] > 8:
#         # vector_B[i] = 'A'
#         vector_B.append('A')
#     elif vector_A[i] > 6:
#         # vector_B[i] = 'B'
#         vector_B.append('B')
#     else:
#         # vector_B[i] = 'C'
#         vector_B.append('C')
#         # print(vector_B[i])
# print(vector_B)

# Two-dimensional list
matrix_A = np.random.randint(10, size=(7, 7))
print(matrix_A)
# print(len(matrix_A))

sub_matrix = []
matrix_B = np.zeros(shape=(7, 7))
# print(matrix_B)
sum = 0
count = 0
for i in range(len(matrix_A)):
    for j in range(len(matrix_A)):
        if i == 0 and j == 0:
            # print(i, j)
            for idx in range(i, i+2):
                for jdx in range(j, j+2):
                    sum += matrix_A[idx, jdx]
                    # count = 4
                    count += 1
        elif i == 0 and i < len(matrix_A)-1 and j > 0 and j < len(matrix_A)-1:
            for idx in range(i, i+2):
                for jdx in range(j-1, j+2):
                    sum += matrix_A[idx, jdx]
                    # count = 6
                    count += 1
        elif i > 0 and i < len(matrix_A)-1 and j == 0 and j < len(matrix_A)-1:
            for idx in range(i-1, i+2):
                for jdx in range(j, j+2):
                    sum += matrix_A[idx, jdx]
                    # count = 6
                    count += 1
        elif i == len(matrix_A)-1 and j == len(matrix_A)-1 :
            for idx in range(i-1, i+1):
                for jdx in range(j-1, j+1):
                    sum += matrix_A[idx, jdx]
                    # count = 4
                    count += 1
        elif i == len(matrix_A)-1  and j < len(matrix_A)-1 :
            for idx in range(i-1, i+1):
                for jdx in range(j-1, j+2):
                    sum += matrix_A[idx, jdx]
                    # count = 6
                    count += 1
        elif i < len(matrix_A)-1  and j == len(matrix_A)-1 :
            for idx in range(i-1, i+2):
                for jdx in range(j-1, j+1):
                    sum += matrix_A[idx, jdx]
                    # count = 6
                    count += 1
        else:
            for idx in range(i-1, i+2):
                for jdx in range(j-1, j+2):
                    sum += matrix_A[idx, jdx]
                    # count = 9
                    count += 1

        print(sum)
        print(count)
        matrix_B[i, j] = int(sum/count)
        matrix_B[i, j] = round(sum/count)
        sum = 0
        count = 0

print(matrix_B)


















