import numpy as np
import time

def docfile(tenfile):
    numbers = []
    with open(tenfile, 'r') as file:
        for line in file:
            numbers.append(float(line.strip())) 
    return numbers

for i in range(1, 11):
    tenfile = f'Test{i}.inp'
    numbers = docfile(tenfile)
    mangsort = np.array(numbers, dtype=np.float64)
    star = time.time()
    sorted = np.sort(mangsort)
    en = time.time()
    print(f"{tenfile}: {en-star}")
