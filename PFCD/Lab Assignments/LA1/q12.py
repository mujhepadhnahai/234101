import math

# Read radius from user
r = float(input("Enter the radius: "))

# Calculate area of circle
area = math.pi * r ** 2

# Calculate volume of sphere
volume = (4/3) * math.pi * r ** 3

# Display results
print("Area of the circle:", area)
print("Volume of the sphere:", volume)
