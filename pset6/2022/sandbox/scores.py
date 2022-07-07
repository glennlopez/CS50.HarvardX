from cs50 import get_int

scores = []

# get 3 number from user
for i in range(3):
    score = get_int(f"Number {i+1}: ")
    #scores.append(score)
    scores = scores + [score]
    #scores += [score]

''' debug print scores
for i in range(3):
    print(f"Number {i+1}: {scores[i]}")
'''

average = sum(scores) / len(scores)
print(f"Average: {average}")