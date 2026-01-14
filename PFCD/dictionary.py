# =======================
# Dictionary Operations with Iterations
# =======================

# 1. Create dictionary
d = {"name": "Alice", "age": 25, "city": "NY"}
print("Original:", d)

# 2. Access values
print(d["name"])
print(d.get("age"))
print(d.get("salary", "Not Found"))

# 3. Add / Update
d["age"] = 26
d["salary"] = 50000
print("After update:", d)

# 4. Delete
d.pop("salary")
print("After pop:", d)

d.popitem()
print("After popitem:", d)

del d["age"]
print("After del:", d)

# 5. Keys, Values, Items
print("Keys:", d.keys())
print("Values:", d.values())
print("Items:", d.items())

# 6. ITERATIONS (All types)

print("\nIterate over keys:")
for key in d:
    print(key)

print("\nIterate over values:")
for value in d.values():
    print(value)

print("\nIterate over key-value pairs:")
for key, value in d.items():
    print(key, "=>", value)

print("\nIterate using index:")
keys = list(d.keys())
for i in range(len(keys)):
    print(keys[i], "=>", d[keys[i]])

print("\nIterate with enumerate:")
for i, (k, v) in enumerate(d.items()):
    print(i, k, v)

# 7. Copy and Clear
d2 = d.copy()
print("\nCopy:", d2)

d2.clear()
print("Cleared copy:", d2)

# 8. fromkeys()
new_dict = dict.fromkeys(["a", "b", "c"], 0)
print("\nFromkeys:", new_dict)

# 9. update()
d.update({"country": "USA", "city": "Boston"})
print("After update():", d)

# 10. setdefault()
d.setdefault("gender", "Female")
print("After setdefault:", d)

# 11. Dictionary comprehension
squares = {x: x*x for x in range(1, 6)}
print("\nComprehension:", squares)

# 12. Merge dictionaries
a = {"x": 1, "y": 2}
b = {"y": 3, "z": 4}
merged = a | b
print("Merged:", merged)

# 13. Nested dictionary iteration
student = {
    "name": "John",
    "marks": {"math": 90, "science": 85}
}

print("\nNested iteration:")
for k, v in student["marks"].items():
    print(k, "=>", v)

# 14. Sorted iteration
print("\nSorted by keys:")
for k in sorted(merged):
    print(k, "=>", merged[k])

# 15. Membership
print("\nMembership test:")
print("name" in d)
print("salary" not in d)


#16 reverse key value
months = {'January': 1, 'February': 2, 'March': 3}
months2 = {number: name for name, number in months.items()}
months2 #{1: 'January', 2: 'February', 3: 'March'}
