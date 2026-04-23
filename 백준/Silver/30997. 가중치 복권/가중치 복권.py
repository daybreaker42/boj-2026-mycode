from itertools import combinations
from fractions import Fraction
from collections import Counter

def get_probability(numbers, counts, selected):
    total = sum(counts)
    not_selected_prob = Fraction(1, 1)
    
    # Calculate probability of not getting selected in K draws
    for _ in range(K):
        prob = Fraction(0, 1)
        for num in selected:
            prob += Fraction(counts[num-1], total)
        not_selected_prob *= (1 - prob)
    
    # Calculate probability of getting selected in bonus draw
    bonus_prob = Fraction(0, 1)
    for num in selected:
        bonus_prob += Fraction(counts[num-1], total)
        
    return not_selected_prob * bonus_prob

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Read input
N, M, K = map(int, input().split())
others_selected = []
counts = [0] * N  # Count how many times each number is selected

# Process others' selections
for _ in range(M-1):
    a, b, c = map(int, input().split())
    others_selected.append((a, b, c))
    counts[a-1] += 1
    counts[b-1] += 1
    counts[c-1] += 1

# Try all possible combinations for Haru
best_prob = Fraction(0, 1)
best_numbers = None

for comb in combinations(range(1, N+1), 3):
    # Add Haru's selection temporarily
    for num in comb:
        counts[num-1] += 1
        
    prob = get_probability(N, counts, comb)
    if prob > best_prob:
        best_prob = prob
        best_numbers = comb
        
    # Remove Haru's selection
    for num in comb:
        counts[num-1] -= 1

# Convert fraction to p/q format
p, q = best_prob.numerator, best_prob.denominator

# Print results
print(p, q)
print(*best_numbers)