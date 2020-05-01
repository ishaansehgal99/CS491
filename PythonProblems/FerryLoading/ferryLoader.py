#
# x = [int(x) for x in input().split()]
#
# def ferry_load(x):
#     i = 0
#     while i < len(x):
#
#         i += 1


import pandas as pd

data = pd.read_csv("wine.data")

region_1 = data[data['Region'] == 1]

# N is 59 > 30
N = len(region_1) # Num rows


x_mean = region_1['Flavanoids'].mean()

STD_UB = ((1/(N-1)) * (sum((region_1['Flavanoids'] - x_mean) ** 2))) ** (0.5)
STD_ERR = STD_UB/(N**0.5)

interval = [x_mean - 3 * STD_ERR, x_mean + 3 * STD_ERR]

print(interval)


region_3 = data[data['Region'] == 3]

# N is 48 > 30
N = len(region_3) # Num rows
print(N)

x_mean = region_3['Flavanoids'].mean()

STD_UB = ((1/(N-1)) * (sum((region_3['Flavanoids'] - x_mean) ** 2))) ** (0.5)
STD_ERR = STD_UB/(N**0.5)

interval = [x_mean - 3 * STD_ERR, x_mean + 3 * STD_ERR]
print(interval)



